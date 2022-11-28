#ifndef QUIZ
#define QUIZ

#include <Arduino.h>





class Vraag {
 public:
 String antwoord;
 String stelling;
 bool goed;
 
  Vraag(String _stelling, String _antwoord){
    stelling = _stelling;
    antwoord = _antwoord;
    goed = false;
    
    }

};









#endif
