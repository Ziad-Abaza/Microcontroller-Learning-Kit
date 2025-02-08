# 🛠️ Embedded Systems Educational Kit - Microprocessor Project  

## 📖 Project Overview  
**University:** Burj Al Arab University of Technology  
**Course:** Microprocessors (3rd Year)  
**Supervisor:** Dr. Osama Al-Nahhas (Head of IT Department)  
**Collaborator:** Mazen Gomaa ([GitHub Repository](https://github.com/Mazen-Gomaa/intro-to-embedded-systems-practical-experiments.git))  

This repository contains **6 practical experiments** from a **15-experiment educational kit** designed for embedded systems learning. Each experiment includes **code, schematics, 3D models, and documentation** to facilitate hands-on experience.  

---  

## 🗂 Repository Structure  
```plaintext
├── Experiments/
│   ├── Experiment_2_Temperature_Fan/      # Temperature-Controlled Fan
│   │   ├── Code/
│   │   ├── Schematics/
│   │   └── 3D_Models/
│   │
│   ├── Experiment_4v2_Wireless_Sensor/    # ESP-NOW Environmental Monitor (Sender/Receiver)
│   ├── Experiment_5_RFID_Access/          # RFID-Based Access Control
│   ├── Experiment_7_Water_Level/          # Water Level Monitoring
│   ├── Experiment_13_Smart_Irrigation/    # Soil Moisture Irrigation System
│   └── Experiment_15_LoRa_Communication/  # LoRa Wireless Communication
│
├── screenshots/                  
└── README.md
```  


## 🔬 Experiments Overview  

### 🔹 Experiment 2: Temperature-Controlled Fan System  
**Objective:** Automate fan speed based on temperature and manual joystick input.  
**Components:**  
- DS18B20 Temperature Sensor  
- 16x2 LCD Display  
- Joystick, MOSFET (IRFZ44N), LED  
**Functionality:**  
- Displays temperature on the LCD.  
- Adjusts fan speed manually via joystick or automatically when temperature exceeds **25°C**.  

---  

### 🔹 Experiment 4v2: Wireless Environmental Monitor (ESP-NOW)  
**Objective:** Transmit temperature, humidity, and motion data wirelessly.  
**Components:**  
- ESP32 (Sender/Receiver)  
- DHT11 Sensor, PIR Motion Sensor  
- OLED Display, DC Motor  
**Functionality:**  
- **Sender:** Reads sensor data and transmits via ESP-NOW.  
- **Receiver:** Displays data on the OLED and activates the motor upon motion detection.  

---  

### 🔹 Experiment 5: RFID-Based Access Control  
**Objective:** Grant access using authorized RFID cards.  
**Components:**  
- MFRC522 RFID Module  
- 16x2 LCD Display  
- Electric Lock  
**Functionality:**  
- Reads the RFID card's UID and validates it against a predefined list.  
- Unlocks the door for **5 seconds** if the card is authorized.  

---  

### 🔹 Experiment 7: Water Level Monitoring  
**Objective:** Detect water levels and trigger alerts.  
**Components:**  
- HC-SR04 Ultrasonic Sensor  
- Buzzer, LED, 16x2 LCD Display  
**Functionality:**  
- Measures distance to the water surface.  
- Alerts via **buzzer and LED** for high/low water levels.  

---  

### 🔹 Experiment 13: Smart Irrigation System  
**Objective:** Automate irrigation based on soil moisture levels.  
**Components:**  
- Soil Moisture Sensor  
- MOSFET-Controlled Water Pump  
- SSD1306 OLED Display  
**Functionality:**  
- Activates the **water pump** when moisture drops below **40%**.  
- Displays soil moisture percentage on the OLED.  

---  

### 🔹 Experiment 15: LoRa Wireless Communication  
**Objective:** Transmit data (button presses and DHT11 readings) via LoRa.  
**Components:**  
- LoRa SX1278 Module  
- DHT11 Sensor, Push Buttons  
- RGB LED, SSD1306 OLED Display  
**Functionality:**  
- **Sender:** Sends button states and DHT11 readings via LoRa.  
- **Receiver:** Displays data on the OLED and provides RGB LED feedback.  

---  

## 📸 Educational Kit Images (Placeholder)  
*Images of the kit will be added soon. Check back later!*  

![Kit Overview](https://github.com/Ziad-Abaza/Microcontroller-Learning-Kit/blob/main/screenshots/Kit_overview_2.jpg)  
![Inside the Kit](https://github.com/Ziad-Abaza/Microcontroller-Learning-Kit/blob/main/screenshots/Kit_overview_3.jpg)  

---  

## 🙏 Acknowledgments  
- **Collaborator:** [Mazen Gomaa](https://github.com/Mazen-Gomaa) for contributing complementary experiments.  
- **Supervisor:** Dr. Osama Al-Nahhas for his guidance and expertise.  

---  

## 🔗 Additional Resources  
For the full **15-experiment educational kit**, visit [Mazen Gomaa's Repository](https://github.com/Mazen-Gomaa/intro-to-embedded-systems-practical-experiments.git).  
