#ifndef KNIGHT_H
#define KNIGHT_H
#include "Weapon.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Knight declaration
class Knight
{
    public:
        Knight(string kn, int ks, string wn, int sr, int hc);
        void display();
        bool onHorse(void);
        bool exhausted(void);
        bool charge(void);
    private:
        string knightName;
        int knightStamina;
        Weapon weaponInHand;
};
#endif

