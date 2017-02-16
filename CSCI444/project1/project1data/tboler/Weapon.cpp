#include "Weapon.h"
#include "Random.h"
#include "Knight.h"
#include <iostream>
#include <string>

using namespace std;

Weapon::Weapon (string n, int a, int b)
    : hit_chance(a), stamina_required(b), name(n)
{
    name=n;
    hit_chance=a;
    stamina_required=b;
}

int Weapon::get_stamina_required(void)
{
    return stamina_required;
}

bool Weapon::did_you_hit(void)
{
    Random r(1,100);
    int rn;
    rn=r.get();
    if (rn<=hit_chance)
        return true;
    else
        return false;
}

void Weapon::wdisplay()
{
   // cout << n << " is using: " << name << " that requires " << stamina_required << " and has a " << hit_chance << "% chance to hit." << endl;
}

void Weapon::wdisplay2()
{
    //cout << n << " is using: " << name << " that requires " << stamina_required << " and has a " << hit_chance << "% chance to hit." << endl;
}
