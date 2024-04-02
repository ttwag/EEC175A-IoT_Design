# Digital Sensing
* Use some digital protocols.
* Use libraries

## Common Protocols
* Serial Peripheral Interface (SPI)
    * an interface bus commonly used to send data between microcontrollers and small peripherals
    * One master with several slaves.
    * Master always initiates communication.
* Inter-Integrated Circuit (I2C)
    * a multi-master, multi-slave, serial computer bus used for attaching lower-speed peripheral ICs to processors and microcontrollers in short-diatnce, intra-board communication.
    * One or more masters with several slaves.
    * Each device has an address.
    * Send information on a single BUS called SDA.
    * There are security issue such as eavesdroppintg.
# 7 - Segment Display
* Common Cathode connects cathodes of LED to 0 and 1 to anode.
* Common Anode connects anode of LED to 1 and 0 to cathode.
* We could multiplex a bus of 8 bits that controls a 7-segments display and have select inputs that sends the data from the bus to a selected diaplay. This reduces the number of Arduino pins we use if there are multiple 7 segment displays.

## MEM Sensors
* Miniaturized machanical and electro-mechanical elements.
* Could be integrated within CMOS on the die.