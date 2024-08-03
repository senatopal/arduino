// Touch-Sensitive Color-Changing Night Lamp
const int redPin = 9;   
const int greenPin = 10;
const int bluePin = 11; 
const int touchPin = 2; 

int touchState=0;
int touchCount=0;

void setup() {
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
  pinMode(touchPin, INPUT); 
}

void loop() {
 touchState=digitalRead(touchPin);
 if (touchState == HIGH){
  touchCount++;
  if(touchCount > 6){
    touchCount=0;
    }
   else{
    changeColor(touchCount);
    delay(200);
      }
    }
  }
}

void changeColor(int index) {
  switch (index) {
    case 0: // Red
      analogWrite(redPin, 255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
      break;
    case 1: // Green
      analogWrite(redPin, 0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 0);
      break;
    case 2: // Blue
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 255);
      break;
    case 3: // Yellow
      analogWrite(redPin, 255);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 0);
      break;
    case 4: // Cyan
      analogWrite(redPin, 0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 255);
      break;
    case 5: // Magenta
      analogWrite(redPin, 255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 255);
      break;
    case 6: // White
      analogWrite(redPin, 255);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 255);
      break;
  }
}
