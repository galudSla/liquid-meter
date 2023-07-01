# Liquid Meter

The Liquid Meter is an Arduino-based project that enables you to measure the liquid level in a tank and display it on a 16x2 LCD screen (1602 LCD). The system utilizes an ultrasonic sensor to calculate the liquid level, volume, and percentage of the tank. It provides real-time updates for efficient monitoring.

## Description

This project consists of an Arduino sketch and the necessary hardware components to measure and display the liquid level in a tank. The ultrasonic sensor is used to determine the distance to the liquid surface, which is then converted into a liquid level measurement. The Arduino calculates the volume and percentage of the liquid level in the tank based on predefined tank dimensions.

## Components

- Arduino UNO board
- Ultrasonic sensor (HC-SR04)
- 1602 LCD (16x2 display)

## Libraries

This project requires the following library:

- LiquidCrystal_I2C

To install the library, follow these steps:

1. Open the Arduino IDE.
2. Go to "Sketch" -> "Include Library" -> "Manage Libraries".
3. In the Library Manager, search for "LiquidCrystal_I2C".
4. Click on "LiquidCrystal_I2C" in the search results and click the "Install" button.


## Installation

1. Connect the ultrasonic sensor and 1602 LCD to the Arduino board according to the pins in the code.
2. Upload the Arduino sketch (`liquid_meter.ino`) to the Arduino board using the Arduino IDE.

## Configuration

Adjust the following variables in the code to match the dimensions of your tank:

- `tankLength`: Length of the tank in meters.
- `tankWidth`: Width of the tank in meters.
- `tankHeight`: Height of the tank in meters.

## Usage

1. Power on the Arduino board.
2. The ultrasonic sensor will continuously measure the distance to the liquid surface.
3. The liquid level, volume in liters, and percentage will be displayed on the 1602 LCD screen.
4. The measurements will update every 4 seconds.

## Authors

- [@galudSla](https://github.com/galudSla)
- email: tedgiann@gmail.com

