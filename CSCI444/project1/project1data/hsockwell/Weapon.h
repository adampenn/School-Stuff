// Hiroko Sockwell, Weapon.h
#ifndef Weapon_H
#define Weapon_H
#include<string>
#include"Weapon.h"
using namespace std;

//Weapon class declaration
class Weapon {
  private:
    int staminaCost;
    int hitChance;
    string name; 
  public:
    Weapon(int s, int h, string n);
    void display();
    int cost();
    int chance();
};
#endif
