int sensorPin=9;
int buzzerPin=11;
int ledPin=8;

void setup() {
  pinMode(sensorPin,INPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
  

}

void loop() {
  int deger=digitalRead(sensorPin);
  if(deger==HIGH)
    {
      digitalWrite(buzzerPin,HIGH);
      digitalWrite(ledPin,HIGH);
      delay(200);
      digitalWrite(buzzerPin,LOW);
      digitalWrite(ledPin,LOW);
      delay(200);
      }
    else{
      digitalWrite(buzzerPin,LOW);
      digitalWrite(ledPin,LOW);
      delay(200);
      
      }

}
