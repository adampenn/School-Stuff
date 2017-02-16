#ifndef KNIGHT_H
#define KNIGHT_H
#include"weapon.h"
#include<iostream>
#include<string>
using namespace std;


//class declaration
class Knight
{
  private:
  int stamina;
  string name;
  bool on_Horse;
  Weapon weapon_in_hand;
  
  public:
  bool attack();
  void unhorse();
  bool exhausted();
  bool onhorse();
  void display();
  void show();
  void set(string n, int s, string t, int sr, int hc)
  {
    name=n;
    stamina = s;
    weapon_in_hand.set(t,sr,hc);
    on_Horse=true;
  }
  int get_stamina();
  string get_name();
  void select(string n, int s){
  	name=n;
  	stamina=s;
  	on_Horse=true;
  }
  void set_name(string n);
  void set_stamina(int sta);
  void set_weapon_in_hand(Weapon wep);
  void set_on_Horse(bool oH);
};

#endif
