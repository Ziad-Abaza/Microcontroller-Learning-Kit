/*
   ********************************************
   *  RFID-Based Access Control System  *
   ********************************************

   This code is designed to control access using an RFID card. 
   It reads the UID of an RFID card and checks if it matches a predefined UID.
   If the UID is authorized, access is granted by unlocking a lock for 5 seconds.
   Otherwise, access is denied.

   Components Used:
   - MFRC522 RFID module (SPI communication)
   - 16x2 LCD display (LiquidCrystal library)
   - An electric lock controlled via digital output (A0)

   Functionality:
   - Reads an RFID card's UID using MFRC522.
   - Displays the UID on an LCD screen.
   - If the UID matches the predefined target UID, the lock is unlocked.
   - If the UID does not match, access is denied.
   - The lock re-locks automatically after 5 seconds.
*/

#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>

// LCD pin configuration
const int RS = 7, EN = 2, DB4 = 3, DB5 = 4, DB6 = 5, DB7 = 6;
LiquidCrystal lcd(RS, EN, DB4, DB5, DB6, DB7);

// MFRC522 RFID module pin configuration
#define RST_PIN 9  // Reset pin
#define SS_PIN 10  // Slave select pin

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

// Predefined authorized UID
byte targetUID[] = {0xEF, 0xD0, 0x70, 0x1E};

// Lock control pin
int lockPin = A0;

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  lcd.begin(16, 2);    // Initialize the LCD
  
  // Display waiting message
  lcd.clear();
  lcd.print("Waiting for RFID...");
  
  SPI.begin();         // Initialize SPI for RFID module
  mfrc522.PCD_Init();  // Initialize MFRC522
  
  pinMode(lockPin, OUTPUT);
  digitalWrite(lockPin, LOW);  // Keep the lock closed by default
}

void loop() {
  // Check if a new RFID card is present
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.print("UID: ");
    
    // Print and display the UID
    lcd.clear();
    lcd.print("UID: ");
    
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      Serial.print(" ");
      lcd.print(mfrc522.uid.uidByte[i], HEX);
      lcd.print(" ");
    }
    
    Serial.println();

    // Check if the UID matches the authorized UID
    if (isTargetUID(mfrc522.uid.uidByte)) {
      Serial.println("Access Granted!");
      lcd.setCursor(0, 1);
      lcd.print("Access Granted!");

      digitalWrite(lockPin, HIGH);  // Unlock the door
      
      delay(5000);  // Keep the lock open for 5 seconds
      
      digitalWrite(lockPin, LOW);  // Lock the door again
    } else {
      Serial.println("Access Denied.");
      lcd.setCursor(0, 1);
      lcd.print("Access Denied.");
    }
    
    // Stop reading the card
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }
}

// Function to check if the scanned UID matches the predefined UID
bool isTargetUID(byte* uid) {
  for (byte i = 0; i < sizeof(targetUID); i++) {
    if (uid[i] != targetUID[i]) {
      return false;
    }
  }
  return true;
}
