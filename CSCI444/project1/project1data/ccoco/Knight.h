/*
** project4
** 		The Knight class declaration
** Christy Coco
** Knight.h
*/

#ifndef KNIGHT_H
#define KNIGHT_H


#include "Weapon.h"


class Knight{
    private:
        string name;
        bool onhorse;
        int stamina;
        Weapon weapon_in_hand;
    public:
        Knight(string,int,string,int,int);
        bool are_you_on_horse();
        bool are_you_exhausted();
        bool charge();
        void unhorse_yourself();
        void display();
};



#endif
