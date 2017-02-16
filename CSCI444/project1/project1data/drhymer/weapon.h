#include<iostream>
#include<string>
#ifndef WEAPON_H
#define WEAPON_H
using namespace std;


class Weapon {
  private:
    int staminaRequired, hitChance;
    string name;
  public:
    void set(string, int, int);
    int getStamina();
    bool hit();
    void display();
};

#endif
