// Name: Mayola Rolfes
// Course: CSCI 111
// Date: 11/11/15
// Assignment: Project 4
// Filename: weapon.h

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
using namespace std;

class Weapon
{
    private:
        string name;
        int stamina_required;
        int hit_chance;

    public:
        Weapon(string, int, int);
        string get_name();
        int get_stamina_required();
        int get_hit_chance();
        void display();
        bool did_you_hit();
};

#endif
