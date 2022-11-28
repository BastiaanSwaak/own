#include <Wire.h> 
#include "rgb_lcd.h"

const int buttonPin = 12;
const int buttonPin2 = 11;
const int buttonPin3 = 10;
const int buttonPin4 = 9;
const int ledPin =  6;
const int ledPin2 =  7;
const int ledPin3 =  5;
const int ledPin4 =  4;

int aantalVar = 0;      

int rondes = 0;
int score = 0;
int gameOver = false;
int locked = false;
int newButtonPressed = true;



void setup() {
  lcd.begin(16, 2);
  
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

}

void loop() {
  int userString [100] = {};
  int string [100] = {};

  for (int arraySize = 0; arraySize < 100; arraySize++) {

    string[arraySize] = random(4, 8);
    delay(60);
    aantalVar ++;
  }

  while (gameOver == false) {

    for (int i = 0; i <= rondes; i++ ) {
      digitalWrite(string[i], HIGH);
      delay (300);
      digitalWrite(string[i], LOW);
    }
    int k = 0;
    while (k <= rondes ) {

      bool button1 = digitalRead(buttonPin);
      bool button2 = digitalRead(buttonPin2);
      bool button3 = digitalRead(buttonPin3);
      bool button4 = digitalRead(buttonPin4);
      
      if (button1 == true && locked == false) {
        userString[k] = 6;
        locked = true;
        newButtonPressed = false;
      }
      if (button2 == true && locked == false) {
        userString[k] = 7;
        locked = true;
        newButtonPressed = false;
      }
      if (button3 == true && locked == false) {
        userString[k] = 5;
        locked = true;
        newButtonPressed = false;
      }
      if (button4 == true && locked == false) {
        userString[k] = 4;
        locked = true;
        newButtonPressed = false;
      }

      if (userString[k] != string[k]) {
        gameOver = true;
      }
      if (userString[k] == string[k] && newButtonPressed == true) {           
        score ++;
        rondes ++;
        k++;
        newButtonPressed = false;
        locked = false;

      }
    }

  }




}

// Schematic-o-matic
