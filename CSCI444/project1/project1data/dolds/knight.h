#ifndef KNIGHT_H
#define KNITH_H
#include"weapon.h"
#include<string>
using namespace std;
//CLASS DECLARATION
class Knight
{
  private:
    string  name;
    Weapon joust_weapon;
    int stamina;
    bool is_mounted;
  public:
    Knight(string name,string weapon, int stam, int hit, int stamina);//constructor
    bool are_you_mounted();      
    bool are_you_exhausted();
    void charge();
    void display();
};
#endif
