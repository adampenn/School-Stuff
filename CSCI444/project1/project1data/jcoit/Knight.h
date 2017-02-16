//Jackson Coit
#ifndef KNIGHT_H
#define KNIGHT_H
#include "Weapon.h"
#include<iostream>
#include<string>
using namespace std;


class knight
{
  private:
    int stamina;
    string name;
    bool on_Horse;
    Weapon weapon_in_hand;

  public:
    bool attack();
    void unhorse();
    bool exhausted();
    bool onhorse();
    void display();
    void set(string n, int s, string t, int sr, int hc);
};
#endif
