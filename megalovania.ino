const int buttonPin = 12;
const int buttonPin2 = 11;
const int buttonPin3 = 10;
const int buttonPin4 = 9;
const int ledPin =  6;
const int ledPin2 =  7;
const int ledPin3 =  5;
const int ledPin4 =  4;

const int buzzPin = 3;
const int c = 293;
const int c2 = 587;
const int a = 440;
const int gsh = 415;
const int g = 392;
const int f = 349;



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
   bool button1 = digitalRead(buttonPin);
    bool button2 = digitalRead(buttonPin2);
    bool button3 = digitalRead(buttonPin3);
    bool button4 = digitalRead(buttonPin4);

    if (button1 == true) {
    delay(1000);
    tone(3, c, 100);
    delay(300);
    tone(3, c, 100);
    delay(300);
    tone(3, c2, 200);
    delay(600);
    tone(3, a, 300);
    delay(900);
    tone(3, gsh, 200);
    delay(600);
    tone(3, g, 200);
    delay(600);
    tone(3, f, 200);
    delay(600);
    tone(3, c, 200);
    delay(300);
    tone(3, f, 100);
    delay(300);
    tone(3, g, 100);            
    }
    if (button2 == true) {

    }
    if (button3 == true) {

    }
    if (button4 == true) {

    }
}
