#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include<string>
#include"Weapon.h"
#include<iostream>

using namespace std;

class Knight {
  public:
    Knight(string name, int stam, string type, int stamr, int hit);
    bool charge();
    bool exhausted_check();
    bool horse_check();
    void unHorse();
    void display();
  private:
    string name;
    int stam;
    Weapon weapon;
    bool horse;
};
#endif
