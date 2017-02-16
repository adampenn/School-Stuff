#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>
using namespace std;

class Weapon{
    public:
        Weapon (string s, int hit, int stamina);
        int get_stamina_required(void);
        bool did_you_hit(void);
        void wdisplay();
        void wdisplay2();
        string name;
        int stamina_required;
        int hit_chance;

    /*private:
        string name;
        int hit_chance;
        int stamina_required;
*/
};


#endif // WEAPON_H
