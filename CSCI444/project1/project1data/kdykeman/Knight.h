#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include<string>
#include"Weapon.h"

using namespace std;

class Knight 
{
  public:
    Knight(string name, int stam, string type, int stamreq, int hit);
    bool charge();
    bool stamina();
    bool mounted();
    void dehorse();
    void display();
  private:
    string name;
    int stam;
    string type;
    Weapon weapon;
    bool horse;
};
#endif
