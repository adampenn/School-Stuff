#include"Weapon.h"
#ifndef KNIGHT_H
#define KNIGHT_H
using namespace std;

//knight class declaration
class Knight {
private:
bool onHorse;
string name;
int stamina;
Weapon weapon;
public:
Knight(string knight, Weapon wp);
bool attack();
void onhorse();
bool still_on_horse();
string getknight();
Weapon getweapon();
int get_stamina_required();
};

#endif
