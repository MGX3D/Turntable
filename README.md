# MGX3D Automatic Turntable

A high precision rotating platform for 100Kg/250lbs typical loads.

![Kinect Scan View](/images/Setup.jpg?raw=true "3D Scanner view")


Description:
------------
This platform was initially designed to automate 3D scanning of people and objects with Kinect v2 and 3D Builder:
- heavy duty: hold a heavy person or average couple, run for 12+ hours non-stop
- powerful drive: spin the person fast enough to avoid scanning artifacts due to movement, breathing, ICD, etc.
- precise rotation: stepper controlled (and USB connected) to experiment with line scanners and algorithms
- low profile: close to the ground increase stability when stepped on
- easy to build: use very few parts that are easy to source
     
The current design has completed more than 2500 scans of people to date, with a typical scan taking only 30 seconds.

Characteristics (typical):
--------------------------
- platform diameter: 500mm (2ft) 
- speed: 0-3 RPM (peripheral speed: 25-50mm/s)
- platform load: up to 300lbs
- resolution: 0.02mm for 450mm OD object (20 arcseconds)

Parts required:
---------------
Warning: not final, might be incomplete. Please be prepared to make adjustments. Unless otherwise noted, eBay/Amazon is a good source for parts.
-  1x - $40 - 450mm Lazy Susan Aluminum Bearing 500 lbs Turntable Bearings (VXB Brand). 
-  1x - $30 - Stepper motor driver: DM420A. Alternative: HY-DIV268N-5A.
-  1x - $55 - NEMA23, torque: 25 Kg cm (350 oz. in) (example: Wantai 57BYGH115-003 / 3.0A, but many others work here). 
              Alternative is a NEMA17 planetary gear motor (not for Fusion scans!)
-  4x -  $4 - M5 30mm socket head screws - for the NEMA23 motor mount. Alternative: M4 >35mm and nuts.
-  1x -  $6 - MXL aluminum pulley 40T 8mm bore (anything between 20T and 40T works - bore has to match the motor. GT2 also works). 
-  1x - $10 - 962MXL Timing Belt, .080" Pitch, 77" Outer Circle, 1/4" Wide (McMaster 1679K686, alternative 3/16" 1679K685) 
-  4x -  $3 - F623ZZ: 3x10x4mm flanged bearing for the belt tensioner. Likely to be upgraded to F634zz.
-  2x -  $1 - M3 20mm with 1 nut and 2 washers each. Holds the bearings in the belt tensioner (will be M4 for F634zz).
-  1x -  $0 - 3D printed part for the NEMA23 mount (STLs in the CAD folder)
-  1x -  $0 - 3D printed part for the belt tensioner (STLs in the CAD folder)
-  1x - $20 - Teensy 2.0. Alternative: any Pulse/Dir/Enable capable electronics (examples: Arduino w/ RAMPS shield and shim from Pololu to DM420A or Raspberry Pi 2 with Windows 10 using GPIO pins, etc). 
-  1x - $20 - 1" 8020 72" aluminum extrusion (1010 profile). Will need to be cut in 32"+20"+20". Alternative: metric t-slot extrusion of 20mm or larger.
-  4x -  $4 - 1/4-20 1/2" pan head screws and t-slot nuts - attach the printed parts (motor mount and tensioner) to the aluminum extrusion. Alternative: use M4-12mm + t-nuts.
-  6x -  $5 - M4 16mm screws + t-slot nuts (Can use 8-24 t-slot nuts,  part number 3275 at 8020.inc). Mounts the bearing to the 8020 extrusion.
-  6x -  $1 - #6-1" wood screws - mounts a wooden platform to the bearing. Alternative - double sided tape. 
-  1x -  $1 - 2+ meters (6+ feet) of 6 wire cable to transmit signal: low voltage: Enable/Pulse/Direction/Ground (3.3-5vcc) and 12V DC power to the stepper controller. Good fit: network cable with 2 pairs of wires for motor power. 
-  1x - $40 -  24" (500mm) disc platform. For 3d scanning of people: preferably 1" thick plywood. Alternative: 1 in. x 24 in. x 2 ft. Pine Edge Glued Panel Round Board at Home Depot (paint or cover with no-slip tape). For other uses: polycarbonate or tempered glass (>3/8", heavy!) or 3/8"-1/2" aluminum disc.
- 12x -  $1 - M4 washers - only needed if the lazy susan bearing is not offset (inside vs outside rings), example VXB bearings.

--
Approximate total cost: **$250**

Additional tools required for assembly: 
   - drill with 4mm and 7mm drills. Hand drill works, drill press is better.
   - metric hex/allen keys for metric M3, M4 and M5 screws (m5 works for SAE 1/4" too)
   - saw for the aluminum extrusion. Hand saw works, table saw is better.


Assembly Instructions:
----------------------
The movement in this platform is a quite unique: the belt goes directly from the 40T motor pulley to the big lazy susan bearing, through a bi-lateral belt tensioner. This simple arrangement works incredibly well in practice as it achieves a zero backlash 18:1 typical reduction at a very low cost. The bearing does not need teeth: due to its very large diameter it achieves zero slip through friction. The incidence angle of the belt is gentle enough to not damage the teeth.

![Turntable Bottom View](/images/TurntableBottom.jpg?raw=true "Bottom view")

![Movement View](/images/motor_assembly.jpg?raw=true "Movement view")

The belt is tensioned by sliding the tensioner towards the  bearing. The tensioner also functions as a vertical guide for the belt. 

![Motor Assembly View](/images/motor_assembly_annotated.jpg?raw=true "Motor assembly")


The motor attaches to the extrusion using the 3d printed mount. In the latest design, the motor mount design has been updated to allow easy repositioning of the motor as well as to increase the strength (the 3D model looks slightly different than the pictures below). The holes that take the M5 screws from the motor are designed to be tapped (M5 tap), if you don't have one you can simply use longer M4 screws and nuts on the other side, there is enough clearance.

![Motor Mount View](/images/motor_mount_annotated.jpg?raw=true "Motor mount")

The lazy susan bearing is attached directly to the aluminum extrusion by drilling 12 through holes, 4mm diameters: 6 holes in the inside ring and 6 holes in the outside ring. The bearings are usually half-way drilled from the factory, those holes work well as a guide. Two drilling operations are required, one through hole the screw itself (4 - 4.25mm dia drill) and a secondary hole one for the screw socket-head cap (7mm dia drill but only 4mm deep!). The screw socket heads need to be sunk so they don't block the rotation of the bearing - this is needed even if the bearing is offset (the offset is typically 1-2mm). Alternatively, one can use 3D printed raisers with M4 pan head screws. If the bearing rings are not vertically offset (typical for VXB bearings) you will need to insert M4 washers between the bearing and the extrusion to eliminate friction.

![Bottom View](/images/platform_bottom.jpg?raw=true "Bottom view")

After the bearing is attached to the extrusion (and the belt tension is roughly correct) the round platform is attached to the bearing with 6 pcs of #6-1" wood screws (and washers). An option here is to use double sided adhesive tape (red in the image), however once mounted like this it won't be possible to access to the screws that go into the extrusion. Double sided tape is however the only option for tempered glass platforms (pictured). The challenging part here is to get the bearing perfectly centered on the platform, the trick is to find the center of the disk and then draw a circle that matches the bearing outside diameter.

![Turntable Top View](/images/TurntableTop.jpg?raw=true "Top view")


Possible applications:
---------------------
- 3D scanning of people - using Kinect v2 and 3D Builder 
- 3D scanning of objects - using laser line scanners
- Rotary axis for CNC machining or 3D Printing
- Showroom displays for heavy objects
- Automatic tool changer for CNCs
- Cake decoration?
- ... and more
