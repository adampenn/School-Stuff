// Clemencia Raby
// Project 4
// Knight.h

#ifndef KNIGHT_H
#define KNIGHT_H

#include "Weapon.h"

class Knight {

    public:

        Knight(string n_n, int n_s, string n_t, int n_sr, int n_hc);
        void display();
        bool exhausted();
        bool on_horse();
        bool attack();
        void unhorse();
        int get_stamina();
        string get_name();

    private:

        string n;
        int s;
        Weapon w;
        bool h;
};

#endif
