int gameOver = false;
int spelrondes = 0;
int score = 0;

void setup() {
  // put your setup code here, to run once:

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
  int buttonOutput = 1;
//button 1 geeft 1 2 geeft 2.....

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
