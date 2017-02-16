//Joeann Eastland
//Header File "Knight"
#ifndef KNIGHT_H
#define KNIGHT_H
//////Filses Included//////
#include "Weapon.h"

////Class Declaration////////////



class Knight

{
  private:
    int stamina;
    string name;
    bool on_Horse;
    Weapon weapon_in_hand;

  public:
    string get_name();
    bool attack();
    void unhorse();
    bool exhausted();
    bool onhorse();
    void display();

    Knight(string n, int s, string t,  int sr, int hc); //Knight's Constructor

};

#endif
