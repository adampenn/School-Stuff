#ifndef WEAPON_H
#define WEAPON_H

//WEAPON CLASS DECLARATION
class Weapon
{
  private:
    int hit_chance;
    int stamina_cost;
  public:
    Weapon( int hit, int stamina);//constructor
    int get();
    bool did_i_hit();
};
#endif
