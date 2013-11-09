/*
*  RedLight! Game Code ENGE-1104 Lab2 Group2
*  @author Brandon Foster ()
*  @author Ryan Connors (rpc80)
*  @author Elaine Khuu () 
*  @author Michelle Becerra ()
*  @author Tiffany Tran ()
*  @version 2013.11.01
*/

// Field Varibles ---------------------------------------------------------------------------
// Array of LEDpin values corresponding to the output pins
int ledPins[12] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

// LEDpin Arrays for each of the 4 LEDs and their Red, Blue, and Green pins
int led0 [3] = { 2, 3, 4 };
int led1 [3] = { 5, 6, 7 };
int led2 [3] = { 8, 9, 10 };
int led3 [3] = { 11, 12, 13 };

// Array of all of the LEDarrays : LEDs[0] == LED0 etc...
int leds [4][3] = { {2,3,4}, {5,6,7}, {8,9,10}, {11,12,13} };

// Color arrays representing the On/Off pins to create a particular color
int red [3] = { 0, 0, 1 };
int blue [3] = { 0, 1, 0 };
int green [3] = { 1, 0, 0 };
int violet [3] = { 1, 1, 0 };
int aqua [3] = { 0, 1, 1};
int orange [3] = { 1, 0, 1 };
int white [3] = { 1, 1, 1 };

// Array of color arrays : colors[0] == red etc...
int colors [7][3] = { {0,0,1}, {0,1,0}, {1,0,0}, {1,1,0}, {0,1,1}, {1,0,1}, {1,1,1} };

// Boolean value for the Red-Light, initialized to False
boolean redLight = false;

//Default inital delay timer
int delayTime;

//Button state integers
int button1State;
int button2State;
int button3State;
int button4State;

//Player Name
String player = "";

//Player's score
int score;

//Gameplay boolean
boolean gameOn;
  
// Setup ------------------------------------------------------------------------------------
void setup() {
  
  // set all the LED pins to OUTPUT
  for (int i = 0; i < 12; i++) 
  {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // sets input for analog pins
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  pinMode (A2, INPUT);
  pinMode (A3, INPUT);
  
  // initializes buttonStates to analogRead
  button1State = analogRead(A0);
  button2State = analogRead(A1);
  button2State = analogRead(A2);
  button2State = analogRead(A3);
  
  //Initialize the player's score to 0
  score = 0;  
  
  //Initialize the delay time for round #1
  delayTime = 1000;
  
  //Print out to the user
 Serial.println("RED-LIGHT");
 Serial.print("Current score: ");
 Serial.print(score);
  
}

//Game Loop -------------------------------------------------------------------------------
void loop() {
  /////////////////////////////////////////////////////////
  // Randomly Light an LED -----------------------------------------------------------------
  int randColor = random(0, 6);
  
  if (randColor == 0)
  {
    redLight = true;
  }
  else 
  {
     redLight = false;
  }
  
  int randLED = random (0, 4);
  
  int light [3] = { };
  
  for (int i = 0; i < 3; i++) {
    light[i] = colors [randColor][i] * leds[randLED][i];
  }
  
  // Light the LED according to the vector mutiplication of color .* led
  for (int i = 0; i < 3; i ++) {
    if (light[i] > 0)
        digitalWrite(light[i], HIGH);
  }
  
  //Sets the delay Timer for the light to be on
  delay(delayTime);
  
  // Turns the light off
  for (int i = 0; i < 3; i ++) {
    if (light[i] > 0)
      digitalWrite(light[i], LOW);
  }
  
  /////////////////////////////////////////
    

  // If when button #1 is pushed, the light is red, the player scores a win
  // Otherwise the player has lost the current round.
  if (redLight) 
  {
    Serial.println("YOU WON!");
    wonLight();
    delay(2000);
    score = score + 1;
    delayTime = delayTime - 50;
    Serial.println("Current Score: ");
    Serial.print(score);
    
  }
  else 
  {
    Serial.println("YOU LOOSE");
    lostLight();
    delay(2000);
  }


}

//-------------------------------------------------------------------------------------------

//Private Helper Methods
  
/**
 * Flash each LED red, three times to signal the player that they lost the round
 * @return true if the button is pressed, otherwise return false.
**/
boolean button1Pushed( ) 
{
  if (analogRead(A0) == 0)
  {
     return true;
  }
  else 
  {
  return false;
  }
}

/**
 * Flash each LED red, three times to signal the player that they lost the round
 * @param delayTime milliseconds to keep each LED on
**/
void lostLight() 
{
  for (int i = 0; i < 3; i++) 
  {
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    digitalWrite(10, LOW);
    digitalWrite(13, LOW);
    delay(100);
  }
}

/**
 * Flash each LED gree, three times to signal the player that they won the round
**/
void wonLight() 
{
  for (int i = 0; i < 3; i++) 
  {
    digitalWrite(3, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);
    delay(100);  
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    delay(100);
  }
}
