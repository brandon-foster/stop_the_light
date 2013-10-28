// array for the pins connected to the LEDs
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

// number of elements in ledPins
int rowLength = sizeof(ledPins) / sizeof(int);

void setup() {
  // set all the LED pins to OUTPUT
  for (int i = 0; i < rowLength; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly: 
  lightRow(100);
}

/*
Light up each LED one at a time
@param delayTime milliseconds to keep each LED on
*/
void lightRow(int delayTime) {
  
  // turn each LED on then off, with specified delay time
  for (int i = 0; i < rowLength; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}
