// Name: Mayola Rolfes
// Course: CSCI 111
// Date: 11/11/15
// Assignment: Project 4
// Filename: knight.cpp

#include "knight.h"
#include <iostream>

Knight::Knight(string n, int s, string w, int hc, int sr) : name(n), 
    stamina(s), weapon_in_hand(w, hc, sr), on_horse(true) {}

string Knight::get_name()
{
    return name;
}

int Knight::get_stamina()
{
    return stamina;
}

Weapon Knight::get_weapon_in_hand()
{
    return weapon_in_hand;
}

bool Knight::attack()
{
    stamina -= weapon_in_hand.get_stamina_required();

    if (weapon_in_hand.did_you_hit())
        return true;
    else
        return false;
}

void Knight::unhorse()
{
    on_horse = false;
}

bool Knight::are_you_on_your_horse()
{
    return on_horse;
}

bool Knight::are_you_exhausted()
{
    if (stamina <= 0)
        return true;
    else
        return false;
}

void Knight::display()
{
    cout << name << " is ";

    if (stamina <= 0)
        cout << "exhausted (stamina=" << stamina << ")." << endl;
    else {
        cout << "not exhausted (stamina=" << stamina << ") and ";

        if (on_horse) {
            cout << "is still on his horse.\n"
                << name << " is using: ";
            weapon_in_hand.display();
        } else
            cout << "has been knocked off of the horse." << endl;
    }
}
