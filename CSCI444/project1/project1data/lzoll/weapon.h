#include<iostream>
using namespace std;
#ifndef WEAPON_H
#define WEAPON_H

class weapon
  {
    private:
  int stamina;
  int hitchance;
  string weapon_type;

    public:
  weapon(string we, int st, int hc);
  int get_stamina();
  bool did_you_hit();
  void display();
  };

#endif
