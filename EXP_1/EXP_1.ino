/*
   ***************************************
   *  Temperature-Controlled Fan System  *
   ***************************************
   
   This code is designed to monitor temperature using a DS18B20 sensor 
   and control a fan based on the temperature level. 
   Additionally, it allows manual speed control using a joystick.
   
   Components Used:
   - DS18B20 Temperature Sensor
   - 16x2 LCD Display (LiquidCrystal Library)
   - Joystick for Manual Speed Adjustment
   - Controlled Fan (via MOSFET IRFZ44N)
   - LED Indicator for High Temperature Alert

   Functionality:
   - Reads temperature from DS18B20 and displays it on LCD.
   - Adjusts fan speed based on joystick input.
   - If temperature exceeds 25°C, the fan is activated and the LED turns on.
   - Prints temperature and fan speed to the Serial Monitor.
*/

#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

// Define LCD pins
const int RS = 10, EN = 8, DB4 = 7, DB5 = 6, DB6 = 5, DB7 = 4;
LiquidCrystal lcd(RS, EN, DB4, DB5, DB6, DB7);

// Define DS18B20 temperature sensor pin
#define ONE_WIRE_BUS 12
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Define joystick, fan, and LED pins
const int joystickY = A4;   
const int fanPWM = 3;       // Fan PWM pin (IRFZ44N)
const int ledPin = 2;       // Red LED pin

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // Initialize LCD
  sensors.begin();  // Start temperature sensor
  pinMode(fanPWM, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  float temperature = readTemperature();
  int fanSpeed = controlFanSpeed();
  displayData(temperature, fanSpeed);
  delay(500); // Delay to update data every half second
}

/**
 * Reads the temperature from the DS18B20 sensor.
 * 
 * @return The temperature in Celsius.
 */
float readTemperature() {
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0); // Read temperature
}

/**
 * Controls the fan speed based on joystick input and temperature.
 * 
 * @return The calculated fan speed.
 */
int controlFanSpeed() {
  int joystickValue = analogRead(joystickY);
  int fanSpeed = map(joystickValue, 0, 1023, 0, 255);

  if (readTemperature() > 25) { 
    analogWrite(fanPWM, fanSpeed);
    digitalWrite(ledPin, HIGH); // Turn on LED
  } else {
    analogWrite(fanPWM, 0); // Turn off fan
    digitalWrite(ledPin, LOW); // Turn off LED
  }
  
  return fanSpeed;
}

/**
 * Displays the temperature and fan speed on the LCD.
 * 
 * @param temperature The temperature to display.
 * @param fanSpeed The fan speed to display.
 */
void displayData(float temperature, int fanSpeed) {
  lcd.clear();
  
  // Display temperature on the first line
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print((char)223); // Degree symbol (°)
  lcd.print("C");
  
  // Display fan speed on the second line
  lcd.setCursor(0, 1);
  lcd.print("Fan Speed: ");
  lcd.print(fanSpeed);
}
