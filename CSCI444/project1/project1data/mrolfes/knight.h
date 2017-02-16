// Name: Mayola Rolfes
// Course: CSCI 111
// Date: 11/11/15
// Assignment: Project 4
// Filename: knight.h

#ifndef KNIGHT_H
#define KNIGHT_H

#include "weapon.h"
#include <string>
using namespace std;

class Knight
{
    private:
        string name;
        int stamina;
        Weapon weapon_in_hand;
        bool on_horse;

    public:
        Knight(string, int, string, int, int);
        string get_name();
        int get_stamina();
        Weapon get_weapon_in_hand();
        bool attack();
        void unhorse();
        bool are_you_on_your_horse();
        bool are_you_exhausted();
        void display();
};

#endif
