# Automative-Control-System-
Automotive Control System project based on ARM
## <span style="color: green"> Introduction </span>
The primary objective of this project is to simulate the control system in the car that is based on some conditions and calculations that need to be fulfilled for the 
car to be ready to be on the road.
## Features
### __Unlock/Lock the car doors__
– Using UART peripheral so the microcontroller can control the car doors from distance.
### Temperature Optimization 
– By using a temperature sensor that sends the temperature value to the microcontroller for it to decide whether to turn on the air conditioning or not based on a predetermined temperature value.
### Battery Level and Tires Pressure Analysis 
– By using pressure sensor and battery level sensor and send their values to the microcontroller for it to decide whether the car’s engine can start or not based on predetermined values for both.
### Collision Avoidance – By using an ultrasonic sensor and sending its value to 
the microcontroller for it to control the braking system and decrease the car speed when the distance from the adjacent vehicle becomes less than a predetermined value.
• An image will be displayed on the TFT to describe the car door status.
• All communications in the system are established through serial connections (UART & SPI). 


