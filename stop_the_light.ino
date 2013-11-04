// array for the pins connected to the LEDs
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

// milliseconds to wait before moving to next LED
int delayTime = 100;

// the button input pin
int buttonPin = 11;

// index of the current LED
int lightPosition = 0;

// number of elements in ledPins
int rowLength = sizeof(ledPins) / sizeof(int);

void setup() {
  // set all the LED pins to OUTPUT
  for (int i = 0; i < rowLength; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // set the button pin to INPUT
  pinMode(buttonPin, INPUT);
}

void loop() {
  next();
  delay(delayTime);
}

/*
Turn off current light then turn on next light
*/
void next() {
  // turn off the current LED
  digitalWrite(ledPins[lightPosition], LOW);
  
  // turn on the next LED
  lightPosition = (lightPosition + 1) % (rowLength); // circular indexing
  digitalWrite(ledPins[lightPosition], HIGH);
}
