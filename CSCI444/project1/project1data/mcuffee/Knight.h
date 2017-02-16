#ifndef KNIGHT_H
#define WEAPON_H
#include"Weapon.h" 
#include"Random.h"
#include<iostream>
#include<string>
using namespace std;

class Knight {
  public: 
    Knight(string n, int st);
    bool on_horse();
    int get();
    bool exhausted();
    void display();
  private:
    string name;
    int stamina;

};
#endif

