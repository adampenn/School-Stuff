//Shandra Flatley
//File: knight.cpp
#include "knight.h"
#include <iostream>

using namespace std;

void Knight::display() //display after every round the knight's status (ex.on horse,stamina)
{
    cout<<name<<" is currently ";
    if (on_horse)
        cout<<"on the horse, ";
    else
        cout<<"off the horse, ";
    if(exhausted())
        cout<<"and is exhausted \n";
    else
        cout<<"with "<<stamina<<" points of stamina.\n";
    cout<<name<<" is holding a " ;
    weapon_in_hand.display();
}

bool Knight::onhorse() //whether knight is on horse not necessarily after being knocked out
{
    if(on_horse)
        return true;
    else
        return false;
}

bool Knight::exhausted() //to tell whether knight is exhausted when stamina reaches 0
{
    if (stamina>0)
        return false;
    else
        return true;
}

bool Knight::attack() //the resulting stamina after attacking/jousting
{
    if(stamina > 0)
    {
        stamina=stamina - weapon_in_hand.get_stamina();
        if(weapon_in_hand.did_you_hit())
            return true;
        else
            return false;
    }else
        return false;
}

void Knight::unhorsed() //if knight is on horse after being attacked
{
    on_horse = false;
}






