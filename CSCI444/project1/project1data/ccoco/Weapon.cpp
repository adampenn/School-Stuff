/*
** project4
** 		The weapon class definetion
** Christy Coco
** Weapon.cpp
*/

#include<iostream>
#include "Weapon.h"
#include "Random.h"

Weapon::Weapon(string t,int hc,int sr)
:type(t), hit_chance(hc), stamina_required(sr)
{
}


int Weapon::get_stamina_required(void){
    return stamina_required;
}


bool Weapon::did_you_hit(void){
    Random r(1,100);
    int rn= r.get();
    if (rn <= hit_chance)
        return true;
    else
        return false;
}


void Weapon::display(void){
    cout<<type<<" that requires "<<stamina_required
		<<" stamina and has a "<<hit_chance<<"% chance to hit."<<endl;
	cout<<endl;
}
