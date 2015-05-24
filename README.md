# MGX3D Automatic Turntable

A high precision rotating platform for 100Kg/220lbs typical loads.

![Turntable Bottom View](/images/TurntableBottom.jpg?raw=true "Bottom view")

Description:
------------
This platform was initially designed to automate 3D scanning of people and objects with Kinect v2 and 3D Builder. I needed a precision, stepper driven, low profile platform to experiment with various modes of scanning. The platform has completed more than 2500 scans of people to date.

Characteristics (typical):
--------------------------
- platform diameter: 0.5 to 1 meter (2 to 3ft appx) 
- speed: 0-3 RPM (peripheral speed: 25-50mm/s)
- loads: up to 300lbs

Parts required (INCOMPLETE and NOT FINAL: order at your own risk):
-----------------------------
- 1x - 450mm Lazy Susan Aluminum Bearing 500 lbs Turntable Bearings (VXB Brand). Will need to be drilled for through holes!
- 1x - Stepper motor driver: DM420A typically found on eBay. Alternative HY-DIV268N-5A.
- 1x - NEMA23, torque: 25 Kg cm (350 oz in). Alternative is a NEMA17 planetary gear motor.
- 4x - M5 30mm (for the NEMA23 mount - alternative is M4 >35mm and nuts)
- 1x - GT2 aluminum pulley 40T 8mm bore (anything between 20T and 40T works - bore has to match the motor). eBay.
- 1x - 962MXL Timing Belt, .080" Pitch, 77" Outer Circle, 1/4" Wide (McMaster 1679K686, alternative 3/16" 1679K685) 
- 2x - M3 20mm with nuts and 2 washers each (for the belt tensioner)
- 4x - F623ZZ: 3x10x4mm flanged bearings (for the belt tensioner)
- 1x - 3D printed part for the NEMA23 mount (STLs in the CAD folder)
- 1x - 3D printed part for the belt tensioner (STLs in the CAD folder)
- 1x - Pulse/Dir/Enable capable electronics (example an Arduino w/ RAMPS shield or Raspberry Pi 2 with Windows 10, etc).
- 6ft - 1" 8020 aluminum extrusion (1010 profile) - this will need to be cut.
- 4x - 1/4-20 1/2" pan head screws and t-slot nuts - attach the printed parts (motor mount and tensioner) to the aluminum extrusion
- 6x - 8-32 screws and t-slot nuts, part number 3275 at 8020.inc. Used to mount the bearing to the 8020 extrusion.
- 6ft - 6 wire cable to transmit signal: low voltage: Enable/Pulse/Direction/Ground (3.3-5vcc) and 12V DC+/DC- to the stepper controller. Alternative is network cable with 2 pairs of wires for motor power. 
- 1x - 24" (500mm) disc. For 3d scanning of people: preferably 1" thick plywood alternative: 1 in. x 24 in. x 2 ft. Pine Edge Glued Panel Round Board at Home Depot (paint or cover with no-slip tape). For other uses: polycarbonate or tempered glass (>3/8", heavy!) or 3/8"-1/2" aluminum disc.
- 1x - Arduino+RAMPS running 3D Printer firmware, motor X hooked to the platform. Alternative is Raspberry Pi 2 + Windows 10, GPIO 5/6/13 wired to the controller.


Assembly Instructions:
----------------------
The movement in this platform is a quite unique: the belt goes directly from 40T motor pulley to the big bearing, through a bi-lateral belt tensioner. This simple arrangment works incredibly well in practice as it achieves a zero backlash 18:1 reduction at a very low cost. The bearing does not need teeth: due to its very large diameter it achieves zero slip through friction. The incidence angle of the belt is gentle enough to not damage the teeth.

![Movement View](/images/motor_assembly.jpg?raw=true "Movement view")

![Motor Assembly View](/images/motor_assembly_annotated.jpg?raw=true "Motor assembly")

![Motor Mount View](/images/motor_mount_annotated.jpg?raw=true "Motor mount")

The (lazy susan) bearing is attached directly to the aluminum extrusion by drilling through the 6 holes for 8-32 screws. Two drilling operations are required, one for the screw itself and a secondary one for the screw sockethead cap (the screw need to be sunk to allow the plaform on top to rotate). 

![Bottom View](/images/platform_bottom.jpg?raw=true "Bottom view")

Next, the platform attaches to the bearing in a similar way: with screws from the bottom. An alternative is to use double sided adhesive tape (red in the image), however once mounted like this it won't be possible to access to the bottom screws anymore. 

![Turntable Top View](/images/TurntableTop.jpg?raw=true "Top view")

Possible uses:
--------------
- 3D Scanning of people - using Kinect v2 and 3D Builder 
- Rotary axis for CNC machining or 3D Printing
- Showroom displays for heavy objects
- Automatic tool changer for CNCs
- Cake decoration?
- ... and more
