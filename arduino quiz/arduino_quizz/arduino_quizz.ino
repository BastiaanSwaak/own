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

const int heel = 500;
const int half = 250;
const int kwart = 125;
const int zestiende = 62.5;

const int buttonPin1 = 12;
const int buttonPin2 = 9;
const int buttonPin3 = 10;
const int buttonPin4 = 11;
const int ledPin = 6;
const int buzzPin = 3;

int state = 0;
Vraag *vragen[4];
int aantalVragen = 1;
int newButtonPressed = false;
int i = 0;
int userAntwoord = 0;
int tunePlayed = false;
int vraagCount = 0;



void setup() {
  Serial.begin(9600);
  Serial.println("alive!");
  lcd.begin(16, 2);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

  pinMode(ledPin, OUTPUT);

  vragen[0] =  new Vraag("2 + 2=", "r:4, g:3, b:5" , 1);
  vragen[1] =  new Vraag("2 + 3=", "r:4, g:3, b:5" , 3);
  vragen[2] =  new Vraag("2 + 1=", "r:4, g:3, b:5" , 2);
  vragen[3] =  new Vraag("2 + 4=", "r:6, g:3, b:5" , 1);


}

void noot(int Hz, int duur, int rust) {
  tone(buzzPin, Hz, duur - 2);
  delay(duur);
  delay(rust);
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

    lcd.setCursor(3, 0);
    lcd.print("druk geel");
    lcd.setCursor(1, 1);
    lcd.print("om te starten");
    if (button4) {
      state = 1;
    }
  }

  if (state == 1) {
    Serial.println(vragen[vraagCount] -> stelling);
    userAntwoord = 0;
    lcd.setCursor(0, 0);
    lcd.print("              ");
    lcd.setCursor(4, 0);
    lcd.print("                  ");
    lcd.setCursor(4, 0);
    lcd.print(vragen[vraagCount] -> stelling);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    lcd.setCursor(0, 1);
    lcd.print(vragen[vraagCount] -> antwoordString);
    if (button1) {
      userAntwoord = 1;
    }
    if (button2) {
      userAntwoord = 2;
    }
    if (button3) {
      userAntwoord = 3;
    }
    if (userAntwoord != 0) {
      state = 2;

    }

  }

  if (state == 2) {
    if (userAntwoord == vragen[vraagCount] -> antwoord) {
      lcd.setCursor(1, 0);
      lcd.print("antwoord goed!      ");
      lcd.setCursor(0, 1);
      lcd.print("                   ");
      noot(c, half, 0);
      noot(c2, half, 0);
      vraagCount ++;
      userAntwoord = 0;
    }
    else if (userAntwoord != vragen[vraagCount] -> antwoord) {
      lcd.setCursor(1, 0);
      lcd.print("antwoord fout!      ");
      lcd.setCursor(0, 1);
      lcd.print("                   ");
      noot(c2, half, 0);
      noot(c, half, 0);
      userAntwoord = 0;
      vraagCount = 0;
    }
    delay(1000);
    if(vraagCount <4){
    state = 1;} else{ state = 3;}
  }
  if(state == 3){
    lcd.setCursor(0, 0);
    lcd.print("              ");
    lcd.setCursor(2, 0);
    lcd.print("alles goed!");
    
    }
}
