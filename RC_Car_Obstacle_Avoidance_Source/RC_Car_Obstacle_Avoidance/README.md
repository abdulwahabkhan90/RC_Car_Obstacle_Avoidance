# 4-Motor Obstacle-Avoiding RC Car

An autonomous Arduino Uno RC car using four DC motors, an HW-130/L298-style motor driver, an HC-SR04 ultrasonic sensor, and an SG90 servo.

## Features
- All four wheels move forward during normal operation.
- Ultrasonic sensor continuously checks for obstacles.
- At approximately 20 cm, the car stops.
- Servo scans left and right.
- The car compares both distances and turns toward the side with more space.
- No HC-05/Bluetooth module is used.

## Pin Configuration
- ENA: D5
- IN1: D4
- IN2: D7
- ENB: D6
- IN3: D8
- IN4: D12
- HC-SR04 TRIG: D9
- HC-SR04 ECHO: D10
- SG90 Servo Signal: D3

## Motor Connections
- Left front + left rear motors: OUT1/OUT2
- Right front + right rear motors: OUT3/OUT4

## Power
- Battery positive: motor driver +12V/VCC input
- Battery negative: motor driver GND
- Arduino GND and motor-driver GND must be common.
- Do not power the DC motors from the Arduino 5V pin.

## Software
Open `RC_Car_Obstacle_Avoidance.ino` in Arduino IDE and upload it to the Arduino Uno.
