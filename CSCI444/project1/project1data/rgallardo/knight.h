//Randell Gallardo
#ifndef KNIGHT_H
#define KNIGHT_H
#include "weapon.h"
#include<iostream>
#include<string>
using namespace std;
class knight
{
  public:
    bool attack();
    void kicked_off();
    bool exhausted();
    bool onhorse();
    void display();
    void set(string n, int stam,string weapon_n, int stam_req, int hit_cha);
      


  private:
    int stamina;
    string name;
    bool mounted;
    Weapon weapon_in_hand;

};
#endif
