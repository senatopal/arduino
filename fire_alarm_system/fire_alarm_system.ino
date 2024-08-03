#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int sensorPin = A0;
int sensorValue = 0;
float temperature = 0;
float voltage = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

int buzzer = 11;
int led = 2;
int relayPin = 8;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  voltage = (sensorValue / 1024.0) * 5000.0;
  temperature = voltage / 10.0;

  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  lcd.print(temperature);
  lcd.print(" °C");

  if (temperature > 24) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
    digitalWrite(relayPin, LOW);
  }

  delay(1000);
}
