#ifndef KNIGHT_H
#define KNIGHT_H
#include"Weapon.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;



class Knight{
    public:
        Knight(string kn, int ks, string wn, int wsr, int whc);
        bool charge(void);
        bool areYouOnHorse(void);
        bool exhausted(void);
        void display(void);
    private:
        string knightName;
        int knightStamina;
        string weaponName;
        int weaponStaminaRequired;
        int weaponHitChance;
        Weapon weaponInHand;    //(string wn, int wsr, int whc);
        bool onHorse;


};

#endif
