//Shandra Flatley
//File: weapons.h

#ifndef WEAPONS_H
#define WEAPONS_H
#include "Random.h"
#include <iostream>
//weapons class decleration
using namespace std;

class Weapon {
private:
    string type;
    int hit_chance;
    int stamina_cost;
public:
    int get_stamina();
    bool did_you_hit();
    void display();
    void set(string, int, int);
};

#endif
