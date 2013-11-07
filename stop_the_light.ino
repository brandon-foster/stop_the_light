
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10}; // array for the pins connected to the LEDs
int redLedPin = 6; // red LED pin number (not the index in the array, the actual pin's number)
int delayTime = 1000; // milliseconds to wait before moving to next LED
int delayDecrement = 200; // milliseconds to decrease delayTime by per level
int buttonPin = 11; // the button input pin
int lightPosition = 9; // index of the current LED, start at 9 for first iteration to light
                       // the 0th LED -- see nextLight() function
int rowLength = sizeof(ledPins) / sizeof(int); // number of elements in ledPins
long millisElapsed = 0; // stores milliseconds since program began
int allowAdvance = 1; // controlled in loop() body to advacne only one level per iteration in the loop() body


void setup() {
  Serial.begin(9600);
  
  // set all the LED pins to OUTPUT
  for (int i = 0; i < rowLength; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // set the button pin to INPUT
  pinMode(buttonPin, INPUT);
}

void loop() {
  
  // advance to the next level if the button is pressed on the red LED
  if (digitalRead(buttonPin) == HIGH && ledPins[lightPosition] == redLedPin && allowAdvance == 1) {
      Serial.println("button pushed while red");
      nextLevel();
      allowAdvance = 0; // can no longer advance to next level, until the next light gets lit
  }
  
  // move on to the next light if [delayTime] milliseconds have elasped
  if (millis() - millisElapsed > delayTime) {
    millisElapsed = millis(); // set
    nextLight();
    allowAdvance = 1; // now allowed to advance to next level
  }
}

/*
Turn off current light then turn on next light
*/
void nextLight() {
  // turn off the current LED
  digitalWrite(ledPins[lightPosition], LOW);
  
  // turn on the next LED
  lightPosition = (lightPosition + 1) % (rowLength); // circular indexing
  digitalWrite(ledPins[lightPosition], HIGH);
  
  Serial.println(ledPins[lightPosition]);
}

/*
Advance to the next level by decreasing delayTime
*/
void nextLevel() {
  flashAll();
  if (delayTime > 200) {
    delayTime -= delayDecrement;
  }
  lightPosition = 9;
  Serial.print("delayTime: ");
  Serial.println(delayTime);
}

/*
Turn all LEDs on and then off, to indicate the completion of the previous level
*/
void flashAll() {
  // turn all LEDs on
  for (int i = 0; i < rowLength; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  
  delay(500);
  
  // turn all LEDs off
  for (int i = 0; i < rowLength; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  
}
