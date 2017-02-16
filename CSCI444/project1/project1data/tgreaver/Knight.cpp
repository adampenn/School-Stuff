//name: Trang Greaver
//file: Knight.cpp
#include "Knight.h"
#include <iostream>
using namespace std;

Knight::Knight(string new_name, int new_stamina, string new_type, int new_stamina_req, int new_hit_chance) : name(new_name), stamina(new_stamina), weapon(new_type, new_stamina_req, new_hit_chance)
{ on_the_horse = true; }

void Knight::display()
{
    cout << name << " : " << stamina << " stamina" << endl;
    weapon.display();
}

bool Knight::are_you_on_your_horse() { return on_the_horse; }
        
bool Knight::are_you_exhausted()
{
    if (stamina >= 1)
    {
        return false;
    }
    return true;
}

void Knight::unhorse() { on_the_horse = false; }

bool Knight::attack()
{
    stamina -= weapon.get_stamina_req();
    if (weapon.hit())
    {
        return true;
    }
    return false;
}

string Knight::get_name() { return name; }
