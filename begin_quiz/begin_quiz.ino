const buttonPin1 =3;
const buttonPin2 =4;
const buttonPin3 =5;
const buttonPin4 =6;
const ledPin = 7;

int pressed = 0;
array vragen = [];

class Vraag {
 antwoord;
 string;
 goed;
 fout; 

   constructor(newAntwoord, newString){
    this.antwoord = newAntwoord;
    this.string = newString;  
    this.goed = false;
    this.fout = false;
    }
  update(){
    if(pressed === !0 && this.antwoord === pressed){this.goed = true;}
    if(pressed === !0 && this.antwoord === !pressed){this.fout = true;}
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

int nieuweVraag = new Vraag(2, "4+4 = 2?, 8?, 9?, 3?");
vragen.push(nieuweVraag);

actoren.update();

  if(vragen[0].goed === true && pressed === !0){
    digitalWrite(ledPin, HIGH);
    }

}
