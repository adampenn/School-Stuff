#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//Weapon Declaration

class Weapon
{
    public:
        Weapon(string wn, int sr, int hc);
        int getStamina(void);
        bool didYouHit(void);
        void display();
    private:
        string weaponName;
        int staminaRequired;
        int hitChance;
};

#endif
