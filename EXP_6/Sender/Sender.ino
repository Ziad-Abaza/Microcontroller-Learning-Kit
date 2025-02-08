// LoRa SX1278 Transmitter Code
// This code sends a signal when a button is pressed.
// An RGB LED (pins 3, 4, and 5) indicates transmission status.
//
// Hardware Connections:
// - LoRa SX1278 Module -> Arduino UNO/NANO
//   GND  -> GND
//   Vcc  -> 3.3V
//   MISO -> D12
//   MOSI -> D11
//   SLCK -> D13
//   Nss  -> D10
//   Di00 -> D2
//   RST  -> D9
// - Buttons: A0, A1, A2, A3
// - RGB LED: 3 (Red), 4 (Green), 5 (Blue)


#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LED_R 3
#define LED_G 4
#define LED_B 5

void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Failed to initialize OLED!"));
    while (1);
  }
  display.clearDisplay();
  displayText("Waiting...");

  Serial.println("LoRa Receiver Initializing...");
  LoRa.begin(915E6);
}

// Display text on OLED screen
void displayText(const char* text) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 25);
  display.println(text);
  display.display();
}

// Reset RGB LED
void resetLEDs() {
  analogWrite(LED_R, 0);
  analogWrite(LED_G, 0);
  analogWrite(LED_B, 0);
}

// Process received message and display on OLED screen
void processMessage(String receivedString) {
  resetLEDs();
  
  if (receivedString.startsWith("T:")) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 20);
    display.println("Temperature & Humidity");
    display.setCursor(0, 40);
    display.println(receivedString);
    display.display();
  } else {
    int receivedVal = receivedString.toInt();
    switch (receivedVal) {
      case 1:
        displayText("Button 1 Pressed");
        analogWrite(LED_R, 255);
        break;
      case 2:
        displayText("Button 2 Pressed");
        analogWrite(LED_G, 255);
        break;
      case 3:
        displayText("Button 3 Pressed");
        analogWrite(LED_B, 255);
        break;
      default:
        displayText("Unknown");
        break;
    }
  }
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String inString = "";
    while (LoRa.available()) {
      inString += (char)LoRa.read();
    }
    Serial.print("Received: ");
    Serial.println(inString);

    processMessage(inString);
  }
}
