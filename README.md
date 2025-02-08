# Educational Microprocessor Experiment Kit

## Overview
This project is a university assignment for the third-year microprocessor course. It consists of an educational kit containing a set of six selected experiments out of a total of fifteen. These experiments are designed to provide hands-on learning experiences in embedded systems.

### Assigned Experiments
The following experiments have been developed as part of this project:
- **Experiment 2**
- **Experiment 4 (Version 2)**
- **Experiment 5**
- **Experiment 7**
- **Experiment 13**
- **Experiment 15 (LoRa Version)**

For more details on the complete set of experiments, refer to Mazen Gomaa's repository:
[GitHub Repository](https://github.com/Mazen-Gomaa/intro-to-embedded-systems-practical-experiments.git)

## Experiment Details
Each experiment includes:
- **Schematic Diagram**
- **3D Model**
- **Code Implementation**

Additionally, a book has been created, documenting the details and explanations of the assigned experiments.

### Experiment 2: Temperature-Controlled Fan System
This experiment monitors temperature using a DS18B20 sensor and controls a fan based on the temperature level, with manual speed control via a joystick.
#### Components:
- DS18B20 Temperature Sensor
- 16x2 LCD Display
- Joystick for Manual Speed Adjustment
- Controlled Fan (via MOSFET IRFZ44N)
- LED Indicator for High Temperature Alert
#### Functionality:
- Reads and displays temperature on LCD
- Adjusts fan speed via joystick
- Activates fan and LED when temperature exceeds 25°C
- Prints data to Serial Monitor

### Experiment 4v2: Wireless Sensor System (ESP-NOW)
This experiment involves a sender-receiver setup using ESP-NOW communication between two ESP32 boards.
#### Sender:
- **Sensors Used:** DHT11 (Temperature & Humidity), PIR (Motion Detection)
- **Communication:** Sends sensor data to receiver via ESP-NOW
#### Receiver:
- **Display:** OLED screen to show received data
- **Actuation:** Controls a motor based on motion detection

### Experiment 5: RFID-Based Access Control System
This system uses RFID to grant or deny access based on a predefined card UID.
#### Components:
- MFRC522 RFID Module
- 16x2 LCD Display
- Electronic Lock (controlled via digital output)
#### Functionality:
- Reads RFID card UID
- Displays UID on LCD
- Unlocks access for authorized UID, denies otherwise
- Auto-locks after 5 seconds

### Experiment 7: Ultrasonic Distance Measurement System
This experiment uses an HC-SR04 ultrasonic sensor to measure distance and display it on an LCD screen.
#### Components:
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD Display
- Buzzer (for proximity alert)
#### Functionality:
- Measures distance using ultrasonic sensor
- Displays real-time distance on LCD
- Activates buzzer if distance is below 10 cm

### Experiment 13: Bluetooth-Controlled Home Automation
This experiment controls home appliances using a Bluetooth module and a mobile application.
#### Components:
- HC-05 Bluetooth Module
- Relay Module
- Mobile App Interface
#### Functionality:
- Receives control commands via Bluetooth
- Toggles appliances on/off
- Displays current status on Serial Monitor

### Experiment 15 (LoRa Version): Long-Range Sensor Data Transmission
This experiment demonstrates long-range communication using LoRa technology.
#### Components:
- LoRa Module (SX1278)
- Temperature & Humidity Sensor (DHT11)
- OLED Display
#### Functionality:
- Transmits sensor data over long distances using LoRa
- Displays received data on an OLED screen
- Ensures low-power, long-range communication

## Additional Resources
Two images of the educational kit are included, showcasing the components and layout.

---
**Developed as part of a third-year microprocessor course.**

