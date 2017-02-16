#include "Knight.h"
#include <iostream>
using namespace std;

Knight::Knight (string n, int stam, string ty, int sr, int hc)
    : weapon_in_hand(ty, hc, sr), name(n), stamana(stam), on_horse(true)
{
}

bool Knight::attack()
{
    int sr;
        sr=weapon_in_hand.get_stamina_required();
        stamana-=sr;
        return weapon_in_hand.did_you_hit();
}

bool Knight::exhausted()
{
    if(stamana<=0)
        return true;
    else
        return false;
}

void Knight::unhorse()
{
    on_horse=false;
}

void Knight::display()
{
        if(exhausted()==true)
            cout << name << " is exhausted." << endl;
        else
            cout << name << " is not exhausted ";

        if (on_horse==true)
            cout << "(stamina=" << /*weapon_in_hand.get_stamina_required()*/ stamana << ") and is still on the horse." << endl;
        else
            cout << "(stamina=" << ") and has been knocked off of the horse." << endl;

        cout << name << " is using: " << weapon_in_hand.name << " that requires " << weapon_in_hand.stamina_required << " stamina and has a " << weapon_in_hand.hit_chance << "% chance to hit." << endl;
        cout << endl;
        weapon_in_hand.wdisplay();
}

void Knight::display2()
{
        if(exhausted()==true)
            cout << name << " is exhausted." << endl;
        else
            cout << name << " is not exhausted ";

        if (on_horse==true)
            cout << "(stamina=" << /*weapon_in_hand.get_stamina_required()*/ stamana << ") and is still on the horse." << endl;
        else
            cout << "(stamina=" << ") and has been knocked off of the horse." << endl;

        cout << name << " is using: " << weapon_in_hand.name << " that requires " << weapon_in_hand.stamina_required << " stamina and has a " << weapon_in_hand.hit_chance << "% chance to hit." << endl;
        cout << endl;
        weapon_in_hand.wdisplay();
}
