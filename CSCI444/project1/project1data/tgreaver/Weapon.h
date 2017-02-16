//name: Trang Greaver
//file: Weapon.h
#ifndef WEAPON_H
#define WEAPON_H

#include <string>
using namespace std;

class Weapon
{
    private:
        string type;
        int stamina_req;
        int hit_chance;

    public:
        Weapon(string, int, int);
        void display();
        bool hit();
        int get_stamina_req();
};

#endif
