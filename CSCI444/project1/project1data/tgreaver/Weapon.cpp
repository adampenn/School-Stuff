//name: Trang Greaver
//file: Weapon.cpp
#include "Weapon.h"
#include "Random.h"
#include <iostream>

Weapon::Weapon(string new_type, int new_stamina_req, int new_hit_chance)
    : type(new_type), stamina_req(new_stamina_req), hit_chance(new_hit_chance)
{}

void Weapon::display()
{
    cout << type << " that takes " << stamina_req << " stamina to use and has a " << hit_chance << "% chance of hitting the opponent." << endl;
}

bool Weapon::hit()
{
    Random random_number(1, 100);
    if (random_number.get() <= hit_chance)
    {
        return true;
    }
    return false;
}

int Weapon::get_stamina_req() { return stamina_req; }
