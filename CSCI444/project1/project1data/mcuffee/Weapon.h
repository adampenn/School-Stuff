#ifndef WEAPON_H
#define WEAPON_H
#include<string>
#include"Random.h"
using namespace std;

class Weapon {
  public:
    Weapon(string t, int h, int s);
    bool did_you_hit();
    int get();
    int stamina_cost();
    void display();
//    string weapon_type();
  private:
    string type;
    int stamina_required;
    int hit_chance;
};
#endif
