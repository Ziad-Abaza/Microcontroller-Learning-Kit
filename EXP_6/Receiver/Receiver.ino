// LoRa SX1278 Receiver Code
// This code receives a signal and displays the corresponding message on an OLED screen.
// An RGB LED (pins 3, 4, and 5) indicates the received message.
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
// - RGB LED: 3 (Red), 4 (Green), 5 (Blue)
// - OLED Display: I2C (SDA, SCL)

#include <SPI.h>
#include <LoRa.h>
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#define BTN0 A0
#define BTN1 A1
#define BTN2 A2
#define BTN3 A3
#define LED_R 3
#define LED_G 4
#define LED_B 5

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(BTN0, INPUT);
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  Serial.println("LoRa Sender Initializing...");
  if (!LoRa.begin(915E6)) {
    Serial.println("LoRa initialization failed!");
    while (1);
  }
}
// Get the button pressed
int getButtonPressed() {
  if (digitalRead(BTN0) == HIGH) return 0;
  if (digitalRead(BTN1) == HIGH) return 1;
  if (digitalRead(BTN2) == HIGH) return 2;
  if (digitalRead(BTN3) == HIGH) return 3;
  return -1;
}

// Send DHT data
void sendDHTData() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Sending Temp: ");
  Serial.print(temperature);
  Serial.print("C, Hum: ");
  Serial.print(humidity);
  Serial.println("%");

  LoRa.beginPacket();
  LoRa.print("T:");
  LoRa.print(temperature);
  LoRa.print(",H:");
  LoRa.print(humidity);
  LoRa.endPacket();

  analogWrite(LED_R, 255);
  delay(100);
  analogWrite(LED_R, 0);
}

// Send a message
void sendMessage(int message) {
  Serial.print("Sending: ");
  Serial.println(message);
  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  analogWrite(LED_R, 255);
  delay(100);
  analogWrite(LED_R, 0);
}

void loop() {
  int message = getButtonPressed();
  if (message != -1) {
    if (message == 0) {
      sendDHTData();
    } else {
      sendMessage(message);
    }
    delay(500);
  }
}
