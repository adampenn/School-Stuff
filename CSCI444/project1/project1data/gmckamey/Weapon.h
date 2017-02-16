//Ginette Mckamey CSCI 111

#include<iostream>
#include<iomanip>
using namespace std; 

#ifndef WEAPON_H
#define WEAPON_H

//Weapon class Declaration

class Weapon {

private:
string weapon_type; 
int stamina_required;
int hit_chance;

public:
int get_stamina_required();
bool did_you_hit();
Weapon(string type, int sr, int hc);
void display();
};
#endif
