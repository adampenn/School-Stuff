#ifndef KNIGHT_H
#define KNIGHT_H
#include "Weapon.h"
#include <iostream>
#include <string>
using namespace std;

class Knight
{
    public:
        Knight(string n, int stam, string ty, int sr, int hc);
        bool attack();
        bool exhausted();
        void unhorse();
        void display();
        void display2();
        bool on_horse;

    private:
        int stamana;
        string name;
        Weapon weapon_in_hand;

};

#endif // KNIGHT_H
