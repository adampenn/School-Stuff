#ifndef WEAPON_H
#define WEAPON_H
#include<string>
using namespace std;
class weapon{
  public:
    int get_stamina();
    bool did_i_hit();
    weapon(string n, int a, int b);
    void display();
  private:
    string type;
    int stamina_required;
    int hit_chance;
};
#endif
