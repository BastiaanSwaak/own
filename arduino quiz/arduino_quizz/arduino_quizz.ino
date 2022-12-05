/* #include "Quiz.cpp"

#include <Wire.h>

#include "rgb_lcd.h"
*/
const int buttonPin1 = 9;
const int buttonPin2 = 10;
const int buttonPin3 = 11;
const int buttonPin4 = 12;
const int ledPin = 6;

int state = 0;
int vragenArray[10] = {};
int aantalVragen = 1;
int newButtonPressed = false;
int i = 0;


void setup() {
  //  lcd.begin(16, 2);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

  pinMode(ledPin, OUTPUT);


}

void loop() {

  // vragenArray[0] = Vraag vraag1("2 + 2", "4");

  bool button1 = digitalRead(buttonPin1);
  bool button2 = digitalRead(buttonPin2);
  bool button3 = digitalRead(buttonPin3);
  bool button4 = digitalRead(buttonPin4);

  if (button1 || button2 || button3 || button4) {
    newButtonPressed = true;
  } else {
    newButtonPressed = false;
  }

  digitalWrite(ledPin, newButtonPressed);
  /*
    if (state == 0){

      while(i < aantalVragen){
         if(newButtonPressed && input == vragenArray[i].antwoord){
              vragenArray[i].goed = true;
           }
            if(newButtonPressed && vragenArray[i].goed == false){
              i = 0;
              newButtonPressed = false;
              input reset
              }
            if(newButtonPressed && vragenArray[i].goed == true){
              i++;
              newButtonPressed = false;
              input reset
              }

        }







    }
  */


}
