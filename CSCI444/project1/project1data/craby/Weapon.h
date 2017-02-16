// Clemencia Raby
// Project 4
// Weapon.h

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

using namespace std;

class Weapon {

    public:

        Weapon(string n_t, int n_hc, int n_sr);
        int get_stamina_required();
        int get_hit_chance();
        bool did_you_hit();
        void display();

    private:

        string t;
        int hc;
        int sr;
};

#endif
