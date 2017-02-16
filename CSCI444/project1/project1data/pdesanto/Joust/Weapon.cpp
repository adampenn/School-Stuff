#include <iostream>
#include <iomanip>
#include "Weapon.h"

using namespace std;

void Weapon::set(string n, int s, int h)
{
    name=n;
    stam_required=s;
    hit=h;
}

void Weapon::display()
{
 cout<< name << ",needs" << stam_required= << "stamina, and has hit chance of " << hit;   

}

void Weapon::get_stam()
{
    return stam_required;
}

bool Weapon::hit()
{
    Random chance(1, hit);

    if(chance.get() == hit)
        return true;
    else
        return false;
}


