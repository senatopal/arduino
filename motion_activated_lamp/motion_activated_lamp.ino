int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int ldrPin = A0;
int potPin = A1;
int motionPin = 2;
int ldrValue;
int potValue;
int motionState;

void setup() {
  Serial.begin(9600); 
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(motionPin, INPUT); 
}

void loop() {
  ldrValue = analogRead(ldrPin);
  potValue = analogRead(potPin);
  motionState = digitalRead(motionPin);

  int redValue = map(potValue, 0, 1023, 0, 255);
  int greenValue = map(potValue, 0, 1023, 0, 255);
  int blueValue = map(potValue, 0, 1023, 0, 255);

  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  if (motionState == HIGH) {
    Serial.println("Motion detected, turning on the lamp");
    int brightness = map(ldrValue, 0, 1023, 0, 255);
    // to achieve white light, the three colors need to be set at equal intensity
    analogWrite(redPin, brightness); 
    analogWrite(greenPin, brightness);
    analogWrite(bluePin, brightness);
  } else {
    Serial.println("No motion detected, turning off the lamp");
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);

    delay(200);
  }
  
  
