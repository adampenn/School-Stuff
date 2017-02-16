#include<iostream>
#include<string>
#include"weapon.h"
#ifndef KNIGHT_H
#define KNIGHT_H
using namespace std;


class Knight 
{
  private:
    int stamina;
    bool onHorse;
    string name;
    Weapon weapon_in_hand;
  public:
    bool attack();
    void unhorse();
    bool exhausted();
    bool onhorse();
    void display();
    void set(string n, int s, string t, int sr, int hc);
    {
      name=n;
      stamina=s;
      weapon_in_hand.set(t,sr,hc);
      onHorse=true;
   }
}; 
#endif
