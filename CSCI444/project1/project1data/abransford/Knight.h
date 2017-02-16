#ifndef _KNIGHT_H_
#define _KNIGHT_H
#include "weapon.cpp"
#include <string>
class Knight {

    private:
    int staminaknight;
    string knightname;
    bool isOnhorse;
    weapon knightsweapon;

    public: 

    bool attack();
    void isKnocked();
    bool knightIsExausted();
    bool onhorse();
    void showstats();
    void setstats(string,int,string,int,int);

    

};
#endif

