/*

        MGX3D 3D Scanning Turntable Controller


Copyright (c) 2015, Marius Gheorghescu. All rights reserved.

mariusg (at) live.com / www.mariusg.com / www.github.com/mgx3d/


Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions 
are met:

1. Redistributions of source code must retain the above copyright 
notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright 
notice, this list of conditions and the following disclaimer in the 
documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/


// pinout configuration for Teensy 2.0
int stepPin = 19;
int enblPin = 21;
int dirPin = 20;
int readoutPin = 17;

// test rotation: 300rpm (5rps, pulse at rougly 1-16Khz), assume 20:1 reduction
unsigned int turnFactor=1;
unsigned int speedFactor=1;
unsigned int lhDelayFactor=3;
unsigned int hlDelayFactor=5;
unsigned int accRampFactor=64;
unsigned int accRampBeta=32;

int paramSlot=0;

// RawHID packets are always 64 bytes
byte buffer[64];

void setup()
{
  pinMode(stepPin, OUTPUT);
  pinMode(enblPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  pinMode(readoutPin, INPUT);
  
  digitalWrite(enblPin, HIGH);
  digitalWrite(dirPin, HIGH);
  
  Serial.begin(9600);
  Serial.println(F("MGX3D Turntable v1.00 Initialized"));
}

void run_motor(unsigned int nSteps, unsigned int lhDelay, unsigned int hlDelay, unsigned int accRamp=0, unsigned int accBeta=0)
{
  for (int i=0; i<64; i++) {
      buffer[i] = 0;
  }
  
  Serial.print(F("RUN: ")); 
  
  Serial.print(F(" steps=")); Serial.print(nSteps);  
  Serial.print(F(" LHus=")); Serial.print(lhDelay);
  Serial.print(F(" HLus=")); Serial.print(hlDelay);
  Serial.print(F(" accRamp=")); Serial.print(accRamp);
  Serial.print(F(" accBeta=")); Serial.print(accBeta);
       
  Serial.println(F(""));

  // run the motor
  for (unsigned int i=0; i<nSteps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(hlDelay);
    digitalWrite(stepPin, LOW);
    
    if (i<accRamp) {
      // accelerate
      //Serial.println((accRamp-i)*accBeta);
      delayMicroseconds(lhDelay + (accRamp-i)*accBeta);
    } else if (i > (nSteps - accRamp)) {
        // decelerate
      //Serial.println((i-nSteps + accRamp)*accBeta);
      delayMicroseconds(lhDelay + (i-nSteps + accRamp)*accBeta);
    } else {
      delayMicroseconds(lhDelay);
    }
  }

  // measure
  for(int i=0;i<32;i++) {
      int val = analogRead(readoutPin);
      buffer[i*2] = highByte(val);
      buffer[i*2 + 1] = lowByte(val);      
  }

  // send data      
  int n = RawHID.send(buffer, 100);
  if (n > 0) {
      // Serial.println(F("Depth data sent"));
  } else {
      Serial.println(F("Unable to transmit packet"));
  }

}

void loop() 
{
  int n = RawHID.recv(buffer, 0); // 0 timeout = do not wait
  if (n > 0) {
    // the computer sent a message.
    Serial.print(F("Received packet, command="));
    Serial.print((int)buffer[0]);

    // HL delay
    Serial.print(F(" param1="));
    Serial.print((int)buffer[1]);

    // LH delay
    Serial.print(F(" param2="));
    Serial.print((int)buffer[2]);

    // acceleration beta factor
    Serial.print(F(" param3="));
    Serial.print((int)buffer[3]);

    // steps
    Serial.print(F(" wparam1="));
    Serial.print(*(int*)&buffer[4]);    

    // acceleration ramp steps
    Serial.print(F(" wparam2="));
    Serial.print(*(int*)&buffer[8]);

    Serial.println("");
    
    switch (buffer[0])
    {
    case 0x00:
      // paramer rotation
      run_motor(*(unsigned int*)&buffer[0x04], *(unsigned int*)&buffer[0x08], 
        *(unsigned int*)&buffer[0x0C], *(unsigned int*)&buffer[0x10], *(unsigned int*)&buffer[0x14]);
      break;

    case '+':
      switch(paramSlot) {
        case 0: 
          turnFactor++;
          break;
          
        case 1:
          lhDelayFactor++;
          break;
          
        case 2:
          hlDelayFactor++;
          break;

        case 3:
          accRampFactor++;
          break;                  

        case 4:
          accRampBeta++;
          break;
      }
      break;
      
    case '-':
      switch(paramSlot) {
      case 0:
        turnFactor = max(1, turnFactor--);
        break;
        
      case 1:
        lhDelayFactor = max(0, lhDelayFactor--);
        break;
        
      case 2:
        hlDelayFactor = max(0, hlDelayFactor--);
        break;

      case 3:
        accRampFactor = max(0, accRampFactor--);
        break;
        
      case 4:
        accRampBeta = max(0, accRampBeta--);
        break;
      }
      break;
      
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
      paramSlot = buffer[0]-'1';
      break;
    
    case 'r':      
        //int speedFactor = 1<<(buffer[0]-'1');
        run_motor(turnFactor*200*speedFactor, 8192/(1+pow(1.3,32-lhDelayFactor)), 8192/(1+pow(1.3,32-hlDelayFactor)), accRampFactor*speedFactor, accRampBeta/speedFactor);
        break;
    }
  }  
}
