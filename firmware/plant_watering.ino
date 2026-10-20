```cpp
// ==========================================
// AUTO PLANT WATERING SYSTEM
// RTC Scheduled & Capacitive Threshold Irrigation
// Developer: Aditya Kumar Gupta (aditya.geninfo.in)
// ==========================================

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define MOISTURE_PIN A0
#define RELAY_PIN    7   // Connected to pump relay

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int DRY_THRESHOLD = 550; // Below 40% VWC equivalent
const int WET_THRESHOLD = 300;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Pump OFF

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Irrigation");
  lcd.setCursor(0, 1);
  lcd.print("System Initialized");
  delay(2000);
}

void loop() {
  int moistureVal = analogRead(MOISTURE_PIN);
  int moisturePercent = map(moistureVal, 1023, 300, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisturePercent);
  lcd.print("%");

  lcd.setCursor(0, 1);
  if (moistureVal > DRY_THRESHOLD) {
    lcd.print("Status: Watering!");
    digitalWrite(RELAY_PIN, HIGH); // Turn Pump ON
    delay(4000);                   // Water for 4 seconds
    digitalWrite(RELAY_PIN, LOW);  // Turn Pump OFF
  } else {
    lcd.print("Status: Optimal");
    digitalWrite(RELAY_PIN, LOW);
  }

  delay(5000);
}
