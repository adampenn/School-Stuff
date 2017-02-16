//Joeann Eastland
//Weapon Header file 

#ifndef WEAPON_H
#define WEAPON_H

#include<string>
using namespace std;

//////////Weapon Class Declaration/////////

class Weapon
{

  private:
    string name;
    int stamina_Required;
    int hit_Chance;

  public:
    Weapon(string, int, int);   //Crating Weapon's Constructor

    int get_stamina();
    bool hit();
    void display();
};

#endif
