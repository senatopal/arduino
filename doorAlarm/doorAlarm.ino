#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd=(0x27,16,2);

const int motionPin=9;
const int buzzerPin=11;
const int ledPin=8;


void setup() {
 pinMode(motionPin,INPUT);
 pinMode(buzzerPin,OUTPUT);
 pinMode(ledPin,OUTPUT);
 
}

void loop() {
  int value=digitalRead(motionPin);
  if (value==HIGH)
    digitalWrite(buzzerPin,HIGH);
    digitalWrite(ledPin,HIGH);
    lcd.setCursor(3,0);
    lcd.print("Someone is at the door")
    delay(200);
    lcd.clear();
    delay(200);
  else
    digitalWrite(buzzerPin,LOW);
    digitalWrite(ledPin,LOW);
}
