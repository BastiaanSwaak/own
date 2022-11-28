
int rondes = 0;
int score = 0;
int gameOver = false;
int locked = false;
int newButtonPressed = true;
int button1 = true;
int button2 = true;
int button3 = true;
int button4 = true;


void setup() {


}

void loop() {
int userString [100] = {};
int string [100] = {}; // ?? blijven deze variabelen updaten ook al is alleen de while loop bezig??

for (int arraySize = 0; arraySize < 100; arraySize++){

string[arraySize] = random(1, 5);

}

while (gameOver == false){
  
    for (int i = 0; i <= rondes; i++ ){
    digitalWrite(string[i], HIGH);
    delay (300);
    digitalWrite(string[i], LOW);
    }
        int k = 0; 
        while (k <= rondes ){
            if(button1 && locked == false){
              userString[k] = 1;
              locked = true;
              newButtonPressed = false;
              }
            if(button2 && locked == false){
              userString[k] = 2;
              locked = true;
              newButtonPressed = false;
              }
             if(button3 && locked == false){
              userString[k] = 3;
              locked = true;
              newButtonPressed = false;
              }
             if(button4 && locked == false){
              userString[k] = 4;
              locked = true;
              newButtonPressed = false;
              }
      
        if (userString != string[k]){
          gameOver = true;
          }
        if (userString[k] == string[k] && newButtonPressed == true){            // ?? "warning: ISO C++ forbids comparison between pointer and integer"? voor de rest geen errors ??
          score ++;
          k++;
          newButtonPressed = false;
          locked = false;
          
          }
  }
  
  }




}
