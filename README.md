```markdown
# Embedded Systems Educational Kit - Microprocessor Project

## 📖 Project Overview
**University:** Burj Al Arab University Technology 
**Course:** Microprocessors (3rd Year)  
**Supervisor:** Dr. Osama Al-Nahhas (Head of IT Department)  
**Collaborator:** Mazen Gomaa ([GitHub Repository](https://github.com/Mazen-Gomaa/intro-to-embedded-systems-practical-experiments.git))  

This repository contains **6 practical experiments** from a 15-experiment educational kit designed for embedded systems learning. Each experiment includes **code**, **schematics**, **3D models**, and documentation.  

---

## 🗂 Repository Structure
```
├── Experiments/
│   ├── Experiment_2_Temperature_Fan/      # Temperature-Controlled Fan
│   │   ├── Code/
│   │   ├── Schematics/
│   │   └── 3D_Models/
│   │
│   ├── Experiment_4v2_Wireless_Sensor/    # ESP-NOW Environmental Monitor (Sender/Receiver)
│   ├── Experiment_5_RFID_Access/          # RFID-Based Access Control
│   ├── Experiment_7_Water_Level/          # Water Level Monitoring
│   ├── Experiment_13_Smart_Irrigation/    # Soil Moisture Irrigation
│   └── Experiment_15_LoRa_Communication/  # LoRa Wireless Communication
│
├── screenshots/                  
└── README.md
```

---

## 🔍 Experiments Overview

### Experiment 2: Temperature-Controlled Fan System  
**Objective:** Automate fan speed based on temperature and manual joystick input.  
**Components:**  
- DS18B20 Temperature Sensor  
- 16x2 LCD Display  
- Joystick, MOSFET (IRFZ44N), LED  
**Functionality:**  
- Displays temperature on LCD.  
- Adjusts fan speed via joystick or automatically (if >25°C).  

---

### Experiment 4v2: Wireless Environmental Monitor (ESP-NOW)  
**Objective:** Transmit temperature, humidity, and motion data wirelessly.  
**Components:**  
- ESP32 (Sender/Receiver)  
- DHT11 Sensor, PIR Motion Sensor  
- OLED Display, DC Motor  
**Functionality:**  
- **Sender:** Reads sensor data and sends via ESP-NOW.  
- **Receiver:** Displays data on OLED and activates motor on motion detection.  

---

### Experiment 5: RFID-Based Access Control  
**Objective:** Grant access using authorized RFID cards.  
**Components:**  
- MFRC522 RFID Module  
- 16x2 LCD, Electric Lock  
**Functionality:**  
- Validates card UID against a predefined list.  
- Unlocks for 5 seconds if authorized.  

---

### Experiment 7: Water Level Monitoring  
**Objective:** Detect water levels and trigger alerts.  
**Components:**  
- HC-SR04 Ultrasonic Sensor  
- Buzzer, LED, 16x2 LCD  
**Functionality:**  
- Measures distance to water surface.  
- Alerts for high/low levels via buzzer and LED.  

---

### Experiment 13: Smart Irrigation System  
**Objective:** Automate watering based on soil moisture.  
**Components:**  
- Soil Moisture Sensor  
- MOSFET-Controlled Water Pump  
- SSD1306 OLED  
**Functionality:**  
- Activates pump if moisture <40%.  
- Displays moisture percentage on OLED.  

---

### Experiment 15: LoRa Wireless Communication  
**Objective:** Transmit data (button presses/DHT11 readings) via LoRa.  
**Components:**  
- LoRa SX1278 Module  
- DHT11 Sensor, Push Buttons  
- RGB LED, SSD1306 OLED  
**Functionality:**  
- **Sender:** Sends button/DHT11 data via LoRa.  
- **Receiver:** Displays data on OLED and RGB LED feedback.  

---

## 📸 Educational Kit Images (Placeholder)
*Images of the kit will be added soon. Check back later!*
![Kit Overview](https://example.com/kit-photo1.jpg)
![Inside the Kit](https://example.com/kit-photo2.jpg)
---

## 🙏 Acknowledgments
- Collaborator: [Mazen Gomaa](https://github.com/Mazen-Gomaa) for sharing complementary experiments.  
- Supervisor: Dr. Osama Al-Nahhas for guidance.  

---

**🔗 Reference:** For the full 15-experiment kit, visit [Mazen Gomaa's Repository](https://github.com/Mazen-Gomaa/intro-to-embedded-systems-practical-experiments.git).  


This README provides a structured, detailed overview of the project, experiments, and repository. Customize placeholders (e.g., email, university name) as needed.
