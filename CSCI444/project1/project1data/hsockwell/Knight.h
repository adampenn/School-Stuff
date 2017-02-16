// Hiroko Sockwell, Knight.h
#ifndef KNIGHT_H
#define KNIGHT_H
#include<string>
#include"Weapon.h"
using namespace std;

//Knight class declaration
class Knight {
  private:
    bool onHorse;
    int stamina;
    string name;
    Weapon heldWeapon; 
  public:
    Knight(bool o, int s, string n, int c, int h, string w);
    void display();
    void won(bool opponent);
    void unhorsed(bool hit);
    bool lost();
    bool horse();
    bool tired();
    bool charge(int randomNumber);
};
#endif
