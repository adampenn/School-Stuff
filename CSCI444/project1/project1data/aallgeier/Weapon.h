#ifndef WEAPON_H
#define WEAPON_H
#include<string>
using namespace std;

class Weapon
{
  public:
    Weapon(string wp, int hc, int sr);
    int get_hit_chance();
    int get_stamina_required();
    string getknight();
  private:
    string weapon;
    int hit_chance;
    int stamina_required;
};
#endif
