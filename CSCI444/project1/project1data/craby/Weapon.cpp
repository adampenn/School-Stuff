// Clemencia Raby
// Project 4
// Weapon.cpp

#include "Weapon.h"
#include <iostream>
#include "Random.h"

Weapon::Weapon(string n_t, int n_hc, int n_sr)
{
    t = n_t;
    hc = n_hc;
    sr = n_sr;
}

int Weapon::get_stamina_required() 
{
    return sr;
}

int Weapon::get_hit_chance()
{
    return hc;
}

bool Weapon::did_you_hit()
{
    Random theGenerator(1,100);
    int rn;
    rn = theGenerator.get();

    if (rn <= hc)
        return true;
    else
        return false;
}

void Weapon::display()
{
    cout << "Weapon Type: " << t << endl;
    cout << "Weapon Hit Chance: " << hc << "%" << endl;
    cout << "Weapon Stamina: " << sr << endl;
}
