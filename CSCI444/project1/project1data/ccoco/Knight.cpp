/*
** project4
** 		The Knight class definetion
** Christy Coco
** Knight.cpp
*/

#include<iostream>
#include "Knight.h"


Knight::Knight(string n,int s,string t,int hc,int sr)
:weapon_in_hand( t, hc, sr), name(n), stamina(s), onhorse(true)
{
}


bool Knight::are_you_on_horse(){
    return onhorse;
}


bool Knight::are_you_exhausted(){
    if (stamina <= 0)
        return true;
    else
        return false;
}


bool Knight::charge(){
    stamina = stamina - weapon_in_hand.get_stamina_required();
    return weapon_in_hand.did_you_hit();
}


void Knight::unhorse_yourself(){
    onhorse = false;
}


void Knight::display(){
    if (are_you_exhausted())
        cout<<name<<" is exhausted (stamina="<<stamina<<") and";
    else
        cout<<name<<" is not exhausted (stamina="<<stamina<<") and";


    if (onhorse)
        cout<<" is still on the horse."<<endl;
    else
        cout<<" has been knocked off of the horse."<<endl;


    cout<<name<<" is using: ";
	weapon_in_hand.display();
}
