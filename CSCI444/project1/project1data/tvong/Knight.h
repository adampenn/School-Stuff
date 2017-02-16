#ifndef KNIGHT_H
#define KNIGHT_H
#include"Weapon.h"
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class Knight
{ 
  private: 
    int stamina; 
    string name; 
    bool on_horse; 
    Weapon weapon_in_hand; 

  public: 
    bool attack(); 
    void unhorse(); 
    bool exhausted(); 
    bool onhorse();
    void show(); 
    void display(); 
    void set(string n, int s, string t, int sr, int hc)
    {
      name=n; 
      stamina=s; 
      weapon_in_hand.set(t, sr, hc); 
      on_horse=true; 
    }

}; 
#endif   
