//Ginette Mckamey CSCI 111
#include<iostream>
#include<string>
#include"Weapon.h"
#include<iomanip>
using namespace std; 

#ifndef KNIGHT_H
#define KNIGHT_H

//Knight class declaration

class Knight{

private:
bool onhorse;
string name;
int stamina; 
Weapon weapon_in_hand;

public:
bool are_you_on_horse(void);
bool are_you_exhausted(void);
bool charge(void);
void unhorse_yourself(void);
void display();
Knight(string, int, string, int, int );

};
#endif
