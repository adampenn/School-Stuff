#include"Weapon.h"
#include<iostream>
#include<string>

class Knight
{
  public:
    Knight(string n, int s, string wn, int ws, int wh);
    void display(bool mount);
    void getstamina();
    void printname();
    bool checkstam();
    bool checkmount(bool h);
    bool didithit();
  private:
    Weapon w;
    string name;
    int stamina;
    bool h;
    bool hit;
    bool mount;
};
