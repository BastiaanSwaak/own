#include "Quiz.cpp"

#include <Wire.h>

#include "rgb_lcd.h"

rgb_lcd lcd;

const int c = 293;
const int c2 = 587;
const int a = 440;
const int gsh = 415;
const int g = 392;
const int f = 349;

const int buttonPin1 = 12;
const int buttonPin2 = 9;
const int buttonPin3 = 10;
const int buttonPin4 = 11;
const int ledPin = 6;
const int buzzPin = 3;

int state = 0;
int vragenArray[10] = {};
int aantalVragen = 1;
int newButtonPressed = false;
int i = 0;
int userAntwoord = 0;


void setup() {
  lcd.begin(16, 2);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

  pinMode(ledPin, OUTPUT);


}

void noot(int Hz, int duur){
  tone(buzzPin, Hz, duur);
  delay(300);
  }

void loop() {
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

  if (state == 0) {
    lcd.setCursor(2, 0);
    lcd.print("press yellow");
    lcd.setCursor(3, 1);
    lcd.print("to start");
    if (button4) {
      state = 1;
    }
  }

  if (state == 1) {
    Vraag vraag1 = Vraag("2 + 2=","r:4, g:3, b:5" , 1);
    lcd.setCursor(0, 0);
    lcd.print("              ");
    lcd.setCursor(4, 0);
    lcd.print(vraag1.stelling);
    lcd.setCursor(0, 1);
    lcd.print(vraag1.antwoordString);
      if (button1) {
        userAntwoord = 1;
      }
      if (button2) {
        userAntwoord = 2;
      }
      if (button3) {
        userAntwoord = 3;
      }

    
      if(userAntwoord != 0){
      vraag1.update(userAntwoord);
      if (vraag1.goed == true) {
        state = 2;
      }
      if(vraag1.goed == false){
        state = -1;
        }
      }
    
  }

  if (state == 2) {
    userAntwoord = 0;
    lcd.setCursor(0, 0);
    lcd.print("antwoord goed!      ");
    lcd.setCursor(0, 1);
    lcd.print("                   ");
    noot(c, 200);
    noot(c2, 200);
    delay(1000);
    state = 1;
  }



  if (state == -1) {
    userAntwoord = 0;
    lcd.setCursor(0, 0);
    lcd.print("antwoord fout!      ");
    lcd.setCursor(0, 1);
    lcd.print("                   ");
    noot(c2, 200);
    noot(c, 200);
    delay(1000);
    state = 1;
  }

}
