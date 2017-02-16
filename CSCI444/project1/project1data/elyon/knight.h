#ifndef KNIGHT_H
#define KNIGHT_H
#include<string>
#include"weapon.h"
using namespace std;
class knight {
  public:
    bool charge();
    bool exhausted();
    bool are_you_on_horse();
    void display();
    void unhorse_yourself();
    knight(string l,int s,string f,int a,int b);
  private:
    int stamina;
    bool on_horse;
    string name;
    weapon weapon_in_hand;
};
#endif
