# Arduino-Sonar
Overview

This project uses an ultrasonic distance sensor mounted on a rotating servo to scan 180 degrees and detect objects by measuring changes in distance. It calculates the width of detected objects using the distance readings at the object edges and servo angles.

Key functionality:

Rotates servo from 15 to 165 degrees
At each degree, calculates distance using ultrasonic sensor
Detects object edges based on distance threshold
Records edge distance and angle for each detected object
After full 180 degree scan, uses trigonometry to calculate object width

Hardware

Arduino Uno
SG90 Servo motor
HC-SR04 Ultrasonic distance sensor
Jumper wires
Breadboard

Connections

SG90 servo signal pin to Arduino pin D10
HC-SR04:
Trig pin to Arduino pin D11
Echo pin to Arduino pin D12

Code Overview

setup()
Initializes servo, ultrasonic sensor pins, and serial communication
loop()
Rotates servo from 15 to 165 degrees
At each angle, calculate distance using ultrasonic sensor
Detect object edges based on distance change thresholds
Record distance and angle at edges
After scan, calculate object width using edges
calculateDistance() function
Handles ultrasonic sensor pulse/timing to determine distance

Usage

Upload code to Arduino
Open serial monitor window
Rotate servo to scan area
View detected object widths printed after full 180 degree scans
