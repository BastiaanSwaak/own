#include "Quiz.cpp"

#include "rgb_lcd.h"

#include <Wire.h>

rgb_lcd lcd;

const int c = 261.6;
const int d = 293;
const int c2 = c*2;
const int a = 440;
const int gsh = 415;
const int e = 329.6;
const int g = 392;
const int f = 349;
const int f2 = f*2;

const int heel = 600;
const int half = 300;
const int kwart = 150;
const int zestiende = 75;

const int buttonPin1 = 12;
const int buttonPin2 = 9;
const int buttonPin3 = 10;
const int buttonPin4 = 11;
const int ledPin = 6;
const int buzzPin1 = 3;
const int buzzPin2 = 4;

int eindTijd = 0;
int state = 0;
Vraag *vragen[4];
int aantalVragen = 1;
int newButtonPressed = false;
int i = 0;
int userAntwoord = 0;
int tunePlayed = false;
int muziekPlayed = false;
int vraagCount = 0;

int toonHoogtes1[4]
        = { d, c2, g, f };
int toonDuren1[4]
        = { kwart, kwart, kwart, heel };
        
int toonHoogtes2[4]
        = { c, e, g, c2 }; 
int toonDuren2[4]
        = { half, half, half, heel };




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
  tone(buzzPin1, Hz, duur - 2);
  delay(duur);
  delay(rust);
}


void muziek(int x[], int y[]){
    for(int i = 0; i < 4; i++){
          tone(buzzPin1, x[i], y[i]);
        delay(y[i]);
      }
  
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
    lcd.print("druk wit");
    lcd.setCursor(1, 1);
    lcd.print("om te starten");
    if (button4) {
      if(muziekPlayed == false){
    muziek(toonHoogtes2, toonDuren2);
    muziekPlayed = true;}
      state = 1;
    }
  }

  if (state == 1) {
    muziekPlayed = false;
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
      noot(d, half, 0);
      noot(c2, half, 0);
      vraagCount ++;
      userAntwoord = 0;
    }
    else if (userAntwoord != vragen[vraagCount] -> antwoord) {
      lcd.setCursor(1, 0);
      lcd.print("antwoord fout!      ");
      lcd.setCursor(0, 1);
      lcd.print("                   ");
      noot(d, half, 0);
      noot(c, half, 0);
      userAntwoord = 0;
      vraagCount = 0;
    }
    delay(1000);
    if(vraagCount <4){
    state = 1;} else{ state = 3;}
  }
  if(state == 3){
    if(muziekPlayed == false){
    eindTijd = millis();}
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(2, 0);
    lcd.print("alles goed!");
    lcd.setCursor(2, 1);
    lcd.print("restarting");

    if(muziekPlayed == false){
    muziek(toonHoogtes1, toonDuren1);
    muziekPlayed = true;}
    if(millis()/1000 - eindTijd/1000 > 4){
      lcd.setCursor(0, 1);
      lcd.print("                   ");
      lcd.setCursor(0, 0);
      lcd.print("                   ");
      vraagCount = 0;
      muziekPlayed = false;
      state = 0;
      }
    }
}
