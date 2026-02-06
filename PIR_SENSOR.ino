#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// عنوان الشاشة غالباً 0x27 أو 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define PIR_PIN 2
#define BUZZER 3
#define RED_LED 4
#define GREEN_LED 5

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("System Starting");
  lcd.setCursor(0, 1);
  lcd.print("Please Wait...");
  delay(2000);
  lcd.clear();
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {
    // حركة
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, HIGH);

    lcd.setCursor(0, 0);
    lcd.print("Motion Detected ");
    lcd.setCursor(0, 1);
    lcd.print("Alarm ON        ");
  } else {
    // لا حركة
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BUZZER, LOW);

    lcd.setCursor(0, 0);
    lcd.print("No Motion       ");
    lcd.setCursor(0, 1);
    lcd.print("System Safe     ");
  }
}