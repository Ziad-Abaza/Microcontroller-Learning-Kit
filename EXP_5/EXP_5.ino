/**
 * ESP32 Smart Irrigation System
 * --------------------------------
 * This system monitors soil moisture using a sensor and controls a water pump 
 * to maintain optimal moisture levels. The moisture level is displayed on an 
 * OLED screen, and the pump is automatically activated if the soil is too dry.
 *
 * Components:
 * - ESP32
 * - Soil Moisture Sensor
 * - MOSFET for Pump Control
 * - SSD1306 OLED Display
 *
 * Functionality:
 * - Reads moisture sensor data
 * - Displays the moisture level on an OLED screen
 * - Turns ON the pump if the moisture level is below a threshold
 * - Turns OFF the pump after a set duration
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Pin definitions
#define MOISTURE_SENSOR_PIN  13  // Analog pin for soil moisture sensor
#define PUMP_CONTROL_PIN     19  // Digital pin for MOSFET controlling the pump

// Threshold values
#define MOISTURE_THRESHOLD   40  // Moisture percentage below which the pump activates
#define PUMP_ON_TIME         3000 // Pump activation duration in milliseconds (3 sec)

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define OLED_I2C_ADDRESS 0x3C  // Default I2C address for SSD1306

// Initialize OLED display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/**
 * Initializes the system:
 * - Configures pump control pin
 * - Initializes serial communication
 * - Sets up the OLED display
 */
void setup() {
    pinMode(PUMP_CONTROL_PIN, OUTPUT);
    digitalWrite(PUMP_CONTROL_PIN, LOW); // Ensure the pump is OFF at startup

    Serial.begin(115200);
    Serial.println("🌱 ESP32 Smart Irrigation System Initialized...");

    // Initialize OLED display
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed!"));
        for (;;); // Halt execution if OLED initialization fails
    }
    
    display.display();
    delay(2000); // Allow time for OLED setup
    display.clearDisplay();
}

/**
 * Reads soil moisture level and converts it to a percentage.
 * @return int - Moisture level in percentage (0-100)
 */
int getSoilMoisture() {
    int moistureValue = analogRead(MOISTURE_SENSOR_PIN);
    return map(moistureValue, 0, 4095, 100, 0); // Convert raw value to percentage
}

/**
 * Displays the current moisture level on the OLED screen.
 * @param moisturePercent - Current soil moisture percentage
 */
void displayMoistureLevel(int moisturePercent) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("🌿 Moisture Level: ");
    display.print(moisturePercent);
    display.println("%");
}

/**
 * Controls the pump based on soil moisture level.
 * @param moisturePercent - Current soil moisture percentage
 */
void controlPump(int moisturePercent) {
    if (moisturePercent < MOISTURE_THRESHOLD) {
        display.setCursor(0, 10);
        display.println("⚠️ Soil is dry! Turning ON the pump...");
        digitalWrite(PUMP_CONTROL_PIN, HIGH); // Activate the pump
        delay(PUMP_ON_TIME);
        digitalWrite(PUMP_CONTROL_PIN, LOW); // Turn OFF the pump
        display.setCursor(0, 20);
        display.println("✅ Pump turned OFF.");
    } else {
        display.setCursor(0, 10);
        display.println("✅ Soil moisture is sufficient.");
    }

    display.display();
}

/**
 * Main loop: Reads moisture level, displays it, and controls the pump.
 */
void loop() {
    int moisturePercent = getSoilMoisture(); // Get soil moisture level

    displayMoistureLevel(moisturePercent); // Show moisture level on OLED
    controlPump(moisturePercent); // Check if pump needs to be activated

    // Print moisture level to Serial Monitor
    Serial.println("-------------------------------");
    Serial.print("Moisture Level: ");
    Serial.print(moisturePercent);
    Serial.println("%");

    delay(5000); // Wait 5 seconds before next reading
}
