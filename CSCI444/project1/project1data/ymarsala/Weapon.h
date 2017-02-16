#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>
using namespace std;

class Weapon
{
  private:
    string weapname;
    int stamreq;
    int hitchance;
  public: 
    Weapon(string weapname, int stamreq, int hitchance);
    int stamwrecked();
};
#endif
