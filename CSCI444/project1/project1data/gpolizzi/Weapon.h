#ifndef WEAPON_H
#define WEAPON_H
#include<iostream>
#include<iomanip>
using namespace std;



class Weapon{
    public:
        Weapon(string wn, int wsr, int whc);
        int getStaminaRequired(void);
        bool didYouHit(void);
        void display();
   private:
        string weaponName;
        int weaponStaminaRequired;
        int weaponHitChance;
};


#endif
