#ifndef _WEAPON_H_
#define _WEAPON_H_

class Weapon
{
  public:
    Weapon(int stam, int hit);
    int getStam();
    int getHit();
    bool weaponchance();
    
  private:
    int stam;
    int hit;
};

#endif
