//Shandra Flatley
//File: knight.h

#ifndef KNIGHT_H
#define KNIGHT_H

#include "weapons.h"
//knight declerations
using namespace std;

class Knight {
private:
    bool on_horse;
    string name;
    int stamina;
    Weapon weapon_in_hand;
    
public:
    bool exhausted();
    void unhorsed();
    bool onhorse();
    bool attack();
    void display();
    void set (string n,int s, string t, int sc, int hc) //variables that will come from main
    {
        name=n;
        stamina=s;
        weapon_in_hand.set(t, sc, hc);
        on_horse=true;
    }
};



#endif
