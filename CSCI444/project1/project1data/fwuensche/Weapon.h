#ifndef _WEAPON_H_
#define _WEAPON_H_
#include"Random.h"
using namespace std;

class Weapon
{
  public:
    Weapon(string wn, int ws, int wh);
    int checkstamina(int s);
    void displayhitchance();
    void displayname();
    void displaystamreq();
    bool checkhit();
    int joust();
  private:
    int randnum;
    string name;
    int stamreq;
    int hitchance;
};
#endif
