//Shandra Flatley
//File: weapons.cpp

#include "weapons.h"

void Weapon::display()
{
    cout << type << endl;
    cout << "The stats of the weapon are >>" << endl;
    cout << "Hit chance: " << hit_chance << endl;
    cout << "Stamina: " << stamina_cost << endl;
    cout << "Weapon type: " << type << endl;
}

bool Weapon::did_you_hit() //if knight hits, from random file
{
    Random theGenerator(1,100);
    int rn;
    rn=theGenerator.get();
    if(rn<=hit_chance)
        return true;
    else
        return false;
}

void Weapon::set(string n, int s, int h) //sets the variables of the weapon stats
{
    type=n;
    stamina_cost=s;
    hit_chance=h;
}

int Weapon::get_stamina()
{
    return stamina_cost;
}