/*
  Water Level Monitoring System Using Ultrasonic Sensor and LCD Display

  This program measures the water level using an ultrasonic sensor (HC-SR04)
  and displays the distance on an LCD. It also alerts the user with a buzzer
  and LED when the water level is too high or too low.

  Components Used:
  - Ultrasonic Sensor (HC-SR04)
  - 16x2 LCD Display
  - Buzzer
  - LED
  - Arduino Board

  Functionality:
  - Measures water level using an ultrasonic sensor.
  - Displays the water level on an LCD screen.
  - Alerts the user with a buzzer and LED if the water level is too high or too low.

  Author: [Your Name]
  Date: [Date]
*/

#include <LiquidCrystal.h>

// Define LCD pins (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Define ultrasonic sensor pins
const int trigPin = 11;   // Trigger pin for the ultrasonic sensor
const int echoPin = 10;   // Echo pin for the ultrasonic sensor

// Define buzzer and LED pins
const int buzzerPin = 8;  // Pin for the buzzer
const int ledPin = 12;    // Pin for the LED

void setup() {
  initializeSystem();
}

void loop() {
  int distance = measureDistance();
  displayDistance(distance);
  checkWaterLevel(distance);
  delay(500); // Update every 0.5 seconds
}

/**
 * Initializes the system by setting up the LCD, pins, and initial states.
 */
void initializeSystem() {
  lcd.begin(16, 2);
  lcd.print("Water Level:");
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
}

/**
 * Measures the distance using the ultrasonic sensor.
 * @return Measured distance in centimeters.
 */
int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.0344 / 2; // Convert duration to distance in cm
}

/**
 * Displays the measured distance on the LCD.
 * @param distance The measured distance in centimeters.
 */
void displayDistance(int distance) {
  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm   ");
}

/**
 * Checks the water level and triggers the buzzer and LED accordingly.
 * @param distance The measured distance in centimeters.
 */
void checkWaterLevel(int distance) {
  if (distance < 10) {
    alertUser("Water High!", true);
  } else if (distance > 30) {
    alertUser("Water Low!", false);
  } else {
    alertUser("Water Normal", false);
  }
}

/**
 * Alerts the user with a message on the LCD and controls the buzzer and LED.
 * @param message The message to display on the LCD.
 * @param alertState True to activate the buzzer and LED, false to deactivate.
 */
void alertUser(const char* message, bool alertState) {
  digitalWrite(buzzerPin, alertState ? HIGH : LOW);
  digitalWrite(ledPin, alertState ? HIGH : LOW);
  
  lcd.setCursor(0, 1);
  lcd.print(message);
  lcd.print("     ");
}
