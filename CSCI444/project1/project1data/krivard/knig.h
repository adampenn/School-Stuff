#ifndef KNIG_H
#define KNIG_H
#include<iostream>
#include<string>
#include"weap.h"

using namespace std;

class Knight
{
  private:
    string knight_name;
    bool on_horse;
    int knight_stamina;
    //Weapon weapon_in_hand;
  public:
    Knight(string n, bool h, int s);
    bool horse_or_naw();
    bool exhausted();
    //bool charge();
    void display();
};
#endif
