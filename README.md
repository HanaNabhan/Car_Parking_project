# Car Parking System

This project implements a car parking system using an Arduino board. It utilizes infrared sensors to detect the presence of a car in a parking slot and updates the available slot count on an LCD display. The system also includes a servo motor-controlled gate to allow or deny entry based on the availability of parking slots.

## Components Used
- Arduino board
- LCD display (I2C interface)
- Infrared sensors
- Servo motor
- LEDs
- LDR (Light Dependent Resistor)
- Temperature sensor
- Buzzer

## Features
- Tracks the number of available parking slots
- Displays the available slot count on an LCD display
- Controls the gate to allow or deny entry based on slot availability
- Adjusts LED brightness based on ambient light using an LDR
- Displays temperature on the LCD screen and triggers an alarm if the temperature exceeds a certain threshold

## Circuit Diagram


## Installation
1. Connect the components as per the circuit diagram.
2. Upload the provided Arduino code to your Arduino board using the Arduino IDE.
3. Make sure to install the required libraries mentioned in the code.
4. Power up the system.

## Usage
1. The LCD will display the initial welcome message.
2. As a car enters the parking slot, the available slot count will decrease and the gate will open.
3. If the parking is full, a message indicating that the parking is full will be displayed on the LCD.
4. As a car leaves the parking slot, the available slot count will increase and the gate will close.
5. The LCD will display the updated available slot count.
6. The LED brightness will adjust based on the ambient light.
7. The temperature will be displayed on the LCD, and if it exceeds a certain threshold, an alarm will be triggered.

Feel free to customize the code or circuit as per your requirements.
