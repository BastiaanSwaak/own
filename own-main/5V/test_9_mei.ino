
int rondes = 0;
int score = 0;
int gameOver = false;




void setup() {


}

void loop() {
int userString [rondes + 1] = {};
int string [rondes + 1] = {};

while (gameOver == false){
  string[rondes] = random(1, 5);

  for (int i = 0; i =< rondes; i++ ){
  digitalWrite(string[i], HIGH);
  delay (300);
  digitalWrite(string[i], LOW);
  }
  
  if(button1){
    userString = 1;
    }
  if(button2){
    userString = 2;
    }
   if(button3){
    userString = 3;
    }
   if(button4){
    userString = 4;
    }

  
  }




}
