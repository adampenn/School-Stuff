#ifndef _WEAPON_H_
#define _WEAPON_H_
#include<iostream>
#include<string>

class Weapon {
  public:
    Weapon(string name,int stam, int hit);
    int getStam(); 
    int getHit();
    string getName(); 
    bool hit_check();
  private:
    int stam;
    int hit;
    string name;
};
#endif
