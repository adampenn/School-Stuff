#ifndef WEAPON_H
#define WEAPON_H
#include <string>
using namespace std;

class Weapon{
  private:
    string type;
    int stamina_required;
    int hit_chance;

  public:
    int get_stamina_required();
    bool did_you_hit();
    Weapon(string t, int sr, int hc);
    void display();    
  #endif
};
