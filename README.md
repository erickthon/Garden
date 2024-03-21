# Arduino IoT Garden

This project is an IoT-based garden monitoring and control system built using Arduino. It uses various sensors to monitor conditions in the garden and can control a water pump via a relay based on sensor readings.

## Features

- Monitors garden conditions using three sensors.
- Controls a water pump via a relay based on sensor readings.
- Connects to the Arduino IoT Cloud for remote monitoring and control.

## Hardware Requirements

- Arduino board
- Relay
- Water pump
- Soil Moisture Sensors

## Software Requirements

- Arduino IDE
- Arduino IoT Cloud account

## Setup

1. Connect the sensors and relay to your Arduino board. (Provide details about how to connect the hardware.)
2. Connect the water pump to the relay.
3. Open the `garden.ino` file in the Arduino IDE.
4. Upload the code to your Arduino board.
5. Open the Arduino IoT Cloud dashboard to monitor sensor readings and control the water pump.

![Dashboard](https://github.com/erickthon/Garden/blob/main/Dashboard_app.png)

## Watering System

The watering system uses a water pump controlled by a relay. The pump is turned on when the soil is dry (sensor reading less than 60) and turned off when the soil is wet (sensor reading greater than 60). This ensures that your plants are watered automatically whenever they need it.

## Code Explanation

The `garden.ino` file contains the main code for the project. It initializes the sensors and relay in the `setup()` function, then continuously reads the sensors and controls the relay in the `loop()` function. Sensor readings are sent to the Arduino IoT Cloud, and changes to the relay state can be made from the Arduino IoT Cloud dashboard.
