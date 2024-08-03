#include <MPU6050.h>
#include <Wire.h>

MPU6050 MPU;

int GyroX, GyroY, GyroZ;
int buzzer = 10;
int ledPin = 11;  

void setup() {
  pinMode(ledPin, OUTPUT); 
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600); 
  Wire.begin();
  MPU.initialize();
}

void loop() {

  MPU.getRotation(&GyroX, &GyroY, &GyroZ);

  Serial.print("GyroX: ");
  Serial.print(GyroX);
  Serial.print(" | GyroY: ");
  Serial.print(GyroY);
  Serial.print(" | GyroZ: ");
  Serial.println(GyroZ);

  
  if (GyroX < -1000 || GyroX > 1000 || GyroY > 1000 || GyroY < -1000 || GyroZ > 1000 || GyroZ < -1000) {
    tone(buzzer, 1000);   
    digitalWrite(ledPin, HIGH); 
    delay(500);
  } else {
    noTone(buzzer); 
    digitalWrite(ledPin, LOW); 
  }
  
  delay(100); 
}
