// array for the pins connected to the LEDs
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

// red LED pin number (not the index in the array, the actual pin's number)
int redLedPin = 6;

// milliseconds to wait before moving to next LED
int delayTime = 1000;

// the button input pin
int buttonPin = 11;

// index of the current LED
int lightPosition = 0;

// number of elements in ledPins
int rowLength = sizeof(ledPins) / sizeof(int);

// stores milliseconds since program began
long millisElapsed = 0;

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
  
  if (millis() - millisElapsed > delayTime) {
    millisElapsed = millis();
    
    nextLight();
  }
  
  if (digitalRead(buttonPin) == HIGH && ledPins[lightPosition] == 6) {
    Serial.println("button pushed while red");
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
