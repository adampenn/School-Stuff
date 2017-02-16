#ifndef WEAP_H
#define WEAP_H
#include<iostream>
#include<string>
using namespace std;
//Weapon Class DECLARATION
class Weapon
{
  private:
    string weapon_type;
    int stamina_cost;
    int hit_chance;
  public:
    Weapon(string w, int c, int hc);
    int get_stamina_cost(void);
    bool did_you_hit(void);
    void display();
};
#endif
