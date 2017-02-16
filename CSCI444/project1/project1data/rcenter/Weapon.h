// File:  Weapon.h
// Author: Rod Center
// class declaration


#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class Weapon {

  private:
  
  	string _Type;
  	int _StaminaCost;
    int _HitPercent;



  public:
  	//constructor 
    Weapon(string _Type, int _StaminaCost, int _HitPercent);
    int GetCost();
    int SetCost(int StaminaCost);
    bool GetHit();
    void display();
  
};
#endif
