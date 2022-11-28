#include "Quiz.cpp"

#include <Wire.h> 

#include "rgb_lcd.h"

const int buttonPin1 =3;
const int buttonPin2 =4;
const int buttonPin3 =5;
const int buttonPin4 =6;
const int ledPin = 7;
int state = 0;
int vragenArray[10] = {};
int aantalVragen = 1;


void setup() {
  lcd.begin(16, 2);
  
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  
  pinMode(ledPin, OUTPUT);


 }

void loop() {

vragenArray[0] = Vraag vraag1("2 + 2", "4");



if (state == 0){
  
    while(i < aantalVragen){
      int newButtonPressed = false;
      if (knop ingedrukt){
        newButtonPressed = true;
        }
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
            input resetar
            }
      
      }




  
  
  
  }
  


}
