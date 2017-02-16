#include<iostream>
#include<iomanip>
#include<string>
#include "Weapon.h"
using namespace std;

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight
{
  public:
    bool attack();
    void unhorse();
    bool exhausted();
    bool onhorse();
    void display();
    void set(string n, int s, string t, int sr, int hc)
    {
      name=n;
      stamina=s;
      weapon_in_hand.set(t,sr,hc);
      on_Horse=true;
    }
  private:
    int stamina;
    string name;
    bool on_Horse;
    Weapon weapon_in_hand;
};
#endif

