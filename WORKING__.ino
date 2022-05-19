const int buttonPin = 12;
const int buttonPin2 = 11;
const int buttonPin3 = 10;
const int buttonPin4 = 9;
const int ledPin =  6;
const int ledPin2 =  7;
const int ledPin3 =  5;
const int ledPin4 =  4;

int newBpressed = false;
int rondes = 0;
int gameOver = false;


int userString [100] = {};
int string [100] = {};
int music [4] = {587, 392, 293, 329};

void setup() {
  // put your setup code here, to run once:
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
  // put your main code here, to run repeatedly:
while(gameOver == false){
  if (rondes == 0) {
    for (int arraySize = 0; arraySize < 100; arraySize++) {

      string[arraySize] = random(4, 8);

    }
  }
  int reeks = 0;
  while (reeks <= rondes) {
    digitalWrite(string[reeks], HIGH);
    tone(3, music[string[reeks] - 4], 200);
    delay(400);
    digitalWrite(string[reeks], LOW);
    delay(400);
    reeks ++;
  }



  int reeks2 = 0;
  while (reeks2 <= rondes) {
    bool button1 = digitalRead(buttonPin);
    bool button2 = digitalRead(buttonPin2);
    bool button3 = digitalRead(buttonPin3);
    bool button4 = digitalRead(buttonPin4);

    if (button1 == true) {
      tone(3, 293, 100);      
      userString[reeks2] = 6;
      newBpressed = true;
    }
    if (button2 == true) {
      tone(3, 329, 100);
      userString[reeks2] = 7;
      newBpressed = true;
    }
    if (button3 == true) {
      tone(3, 392, 100);
      userString[reeks2] = 5;
      newBpressed = true;
    }
    if (button4 == true) {
      tone(3, 587, 100);
      userString[reeks2] = 4;
      newBpressed = true;
    }
    if (string[reeks2] == userString[reeks2] && newBpressed == true) {
      newBpressed = false;
      reeks2 ++;
      delay(200);
    }

  }





  rondes ++;
  delay(1000);
}
if(gameOver){

    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin2, HIGH);
    delay(100);
    digitalWrite(ledPin3, HIGH);
    delay(100);
    digitalWrite(ledPin4, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    digitalWrite(ledPin2, LOW);
    delay(100);
    digitalWrite(ledPin3, LOW);
    delay(100);
    digitalWrite(ledPin4, LOW);
    delay(100);
    
  }
}
