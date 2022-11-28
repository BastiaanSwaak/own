
int rondes = 0;
int score = 0;
int gameOver = false;
int locked = false;




void setup() {


}

void loop() {
int userString [rondes + 1] = {};
int string [rondes + 1] = {}; // ?? blijven deze variabelen updaten ook al is alleen de while loop bezig??

while (gameOver == false){
  string[rondes] = random(1, 5);
  
    for (int i = 0; i =< rondes; i++ ){
    digitalWrite(string[i], HIGH);
    delay (300);
    digitalWrite(string[i], LOW);
    }
        int k = 0; 
        while (k =< rondes ){
            if(button1 && locked == false){
              userString[k] = 1;
              locked = true;
              }
            if(button2 && locked == false){
              userString[k] = 2;
              locked = true;
              }
             if(button3 && locked == false){
              userString[k] = 3;
              locked = true;
              }
             if(button4 && locked == false){
              userString[k] = 4;
              locked = true;
              }
      
        if (userString != string[k]){
          gameover = true;
          }
        if (userString[k] == string[k]){
          score ++;
          i = 0;
          k = 0;
          
          
          }
  }
  
  }




}
