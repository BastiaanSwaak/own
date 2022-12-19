#ifndef QUIZ
#define QUIZ

#include <Arduino.h>





class Vraag {
  public:
    int antwoord;
    String stelling;
    bool goed;
    String antwoordString;

    Vraag(String _stelling, String _antwoordString, int _antwoord) {
      stelling = _stelling;
      antwoordString = _antwoordString;
      antwoord = _antwoord;
      goed = false;
      Serial.print("constructor  ");
      Serial.println(this -> stelling);
    }

    void update(int _input) {
      if (_input == antwoord) {
        goed = true;
      }
    }

};









#endif
