# TeensyTurn

This shows an example controller running on Arduino Teensy 2.0 (Teensyduino)


Wiring:
-------
The code is configured for Teensy 2.0 / Teensyduino - it maps pins 19,20 and 21 to Step/Direction and respectively Pulse on the controller.

To compile:
----------
1. Install Arduino 1.0.6 or equivalent (http://www.arduino.cc)
2. Install Teensyduino 1.23 or newer (http://www.pjrc.com/teensy/td_download.html)
3. Load the sketch in Arduino
  - Set board type to "Teensy 2.0" or your equivalent
  - Set USB Type to "Raw HID"
  - Click 'Verify'. At this point Arduino should start the Teensy firmware upload app.
  - Reset Teensy - the app should flash it. 
  - Tweak the parameters as needed and repeat the last two steps 
4. Start Serial Monitor and connect at 9600 baud. You should see a message like "MGX3D Turntable v1.00 Initialized"

Usage:
--------
To test the controller, connect to the Teensyduino with raw_hidtest.exe, 

1. Press number keys 1-5 to select 
the stepper control parameters:
    - nSteps - The number of steps (or microsteps) to issue
    - lhDelay - delay (microseconds) between Low-High transitions (example: feed rate)
    - hlDelay - delay (microseconds) between High-Low transitions (example: minimum impulse)
    - accRamp - slope length (impulses) for acceleration/deceleration
    - accBeta - slope angle (delay) for acceleration/deceleration
2. Press '+' or '-' to increase or decrease the parameters as needed 
3. Press 'r' key to issue a move command. If you connect with the Serial Monitor in Arduino and should see the following:
    "
        MGX3D Turntable v1.00 Initialized
        [...]
        Depth data sentReceived packet, command=114 param1=0 param2=0 param3=0 wparam1=0 wparam2=0
        RUN:  steps=600 LHus=432 HLus=5 accRamp=79 accBeta=41
    "

To run the controller with specific parameters, send a 64-byte buffer in the folllwing format:

    Offset  Type        Meaning
    ------  ----        -------
    0x00    byte        always 0x00 
    0x01    byte[3]     reserved
    0x04    uint16      nSteps
    0x08    uint16      lhDelay
    0x0C    uint16      hlDelay
    0x10    uint16      accRamp
    0x14    uint16      accBeta
