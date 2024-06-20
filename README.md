# <code style="color : blue"> Automative-Control-System-</code>
Automotive Control System project based on STM32
##  <code style="color : red">Introduction</code>
The primary objective of this project is to simulate the control system in the car that is based on some conditions and calculations that need to be fulfilled for the 
car to be ready to be on the road.
## <code style="color : red">Features</code>
### **Unlock/Lock the car doors**
– Using UART peripheral so the microcontroller can control the car doors from distance.
### Temperature Optimization 
– By using a temperature sensor that sends the temperature value to the microcontroller for it to decide whether to turn on the air conditioning or not based on a predetermined temperature value.
### Battery Level and Tires Pressure Analysis 
– By using pressure sensor and battery level sensor and send their values to the microcontroller for it to decide whether the car’s engine can start or not based on predetermined values for both.
### Collision Avoidance
– By using an ultrasonic sensor and sending its value to 
the microcontroller for it to control the braking system and decrease the car speed when the distance from the adjacent vehicle becomes less than a predetermined value.
• An image will be displayed on the TFT to describe the car door status.
• All communications in the system are established through serial connections (UART & SPI). 
##  <code style="color : red">Working Scenario</code>
- The driver presses the remote button which sends a signal to unlock the car door if the signal is correct. 
* If the signal is correct, he will insert the key in the car which sends a signal to start the system. 
+ Then the system checks the temperature, battery, and tire pressure levels from their sensors and displays them on the screen. 
• After that the system decides whether to activate the cooling system (air conditioning) or not and whether to start the car engine or not based on the readings that were received from the tire pressure and battery level sensors. 
• When the car starts, the driver can control the speed of the car using the pedal and the collision avoidance system will automatically decrease the car’s speed if the distance between the car and its adjacent vehicle becomes too small



