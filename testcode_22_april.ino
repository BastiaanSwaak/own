
// constants won't change. They're used here to set pin numbers:
int gameOver = false;
int spelrondes = 0;
int score = 0;

const int buttonPin = 12; 
const int buttonPin2 = 11; 
const int buttonPin3 = 10;
const int buttonPin4 = 9;    
const int ledPin =  6;  
const int ledPin2 =  7; 
const int ledPin3 =  5; 
const int ledPin4 =  4;  

int buttonState = 0; 
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;    
    
int buttonOutput = 0;



void setup() {

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
// srand(time(NULL));

// int randNum = (rand() % 4) + 1;


int string [spelrondes + 1] = {};
int playerString [spelrondes + 1] = {};
while (gameOver == false){
  int randNum = (rand() % 4) + 1;
  string[spelrondes] = randNum;
  digitalWrite (string[spelrondes], HIGH);
  delay(1000);
  digitalWrite (string[spelrondes], LOW);
  
if(buttonState){
  buttonOutput = 6;}
if(buttonState2){
  buttonOutput = 7;}
if(buttonState3){
  buttonOutput = 5;}
if(buttonState4){
  buttonOutput = 4;}


playerString[spelrondes] = buttonOutput;


 
  if (playerString[spelrondes] == string[spelrondes]){
    score ++;
    spelrondes ++;
    
    
    }
    else{
      gameOver = true;
      }
  
  
  
  
  
  
  
  
  }
}
