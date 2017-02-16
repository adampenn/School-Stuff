//name: Trang Greaver
//file: Knight.h
#ifndef KNIGHT_H
#define KNIGHT_H
#include "Weapon.h"

class Knight
{
    private:
        string name;
        int stamina;
        Weapon weapon;
        bool on_the_horse;
    public:
        Knight(string, int, string, int, int);
        void display();
        bool are_you_on_your_horse();
        bool are_you_exhausted();
        void unhorse();
        bool attack();
        string get_name();
};

#endif
