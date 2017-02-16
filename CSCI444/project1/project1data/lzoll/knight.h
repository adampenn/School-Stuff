#include<iostream>
using namespace std;
#include"weapon.h"
#ifndef KNIGHT_H
#define KNIGHT_H
class knight
{
  private:
    string name;
    bool on_horse;
    int stamina;
    weapon weapon_inhand;
  public:
    knight(string na, int sta_k, string we, int st, int hc);
    bool attack();
    bool horse_status();
    bool exhausted();
    void display();
    bool are_you_on_horse();
};
#endif
