// Name: Mayola Rolfes
// Course: CSCI 111
// Date: 11/11/15
// Assignment: Project 4
// Filename: weapon.cpp

#include "weapon.h"
#include "Random.h"
#include <iostream>

Weapon::Weapon(string n, int sr, int hc) : name(n), stamina_required(sr),
    hit_chance(hc) {}

void Weapon::display()
{
    cout << name << " that requires " << stamina_required << " stamina"
       << " and has a " << hit_chance << "% chance to hit." << endl; 
}

string Weapon::get_name()
{
    return name;
}

int Weapon::get_stamina_required()
{
    return stamina_required;
}

int Weapon::get_hit_chance()
{
    return hit_chance;
}

bool Weapon::did_you_hit()
{
    Random r(1, 100);
    int num = r.get();

    if (num <= hit_chance)
        return true;
    else
        return false;
}
