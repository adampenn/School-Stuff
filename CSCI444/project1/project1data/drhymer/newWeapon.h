#include<iostream>
#include<string>
#include"Random.h"
using namespace std;

class Weapon
{
  private:
    int staminaRequired, hitChance;
    string name;
  public:
    void set(string, int, int);
    void display();
    int get_stamina();
    bool didYouHit();
};

