const buttonPin1 =3;
const buttonPin2 =4;
const buttonPin3 =5;
const buttonPin4 =6;
const ledPin = 7;

int pressed = 0;
int vragen[] ={};

int vraagstukken[]={
  vraag:"4 + 4 = 2?, 3?, 8?, 1?",
  antwoord: 3
  },{
    vraag: "3 + 4 = 2?, 7?, 4?, 9?"
    antwoord: 7
    };

class Vraag {
 antwoord;
 string;
 goed;
 fout; 

   constructor(newString, newAntwoord){
    this.antwoord = newAntwoord;
    this.string = newString;  
    this.goed = false;
    this.fout = false;
    }

  }

  
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
}

void loop() {
if(buttonPin1){pressed = 1;}else{pressed = 0;}
if(buttonPin2){pressed = 2;}else{pressed = 0;}
if(buttonPin3){pressed = 3;}else{pressed = 0;}
if(buttonPin4){pressed = 4;}else{pressed = 0;}




for(i = 0; i<vraagstukken.length; i++){
  int nieuweVraag = new Vraag(vraagstukken[i].antwoord, vraagstukken[i].vraag);
  vragen.push(nieuweVraag);
  if(pressed != 0 && pressed === vragen[i].antwoord){
  if(vragen[0].goed === true && pressed != 0){
    digitalWrite(ledPin, HIGH);
    }
  
  
  }
 }

}
