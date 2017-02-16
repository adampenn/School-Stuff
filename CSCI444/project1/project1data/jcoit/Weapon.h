//Jackson Coit
#ifndef WEAPON_H
#define WEAPON_H
#include<iostream>
#include<string>


using namespace std;

class Weapon {
  private:
    int stamina_Required, hit_chance;
    string name;

  public:
    void set(string, int, int);
    void display();
    int get_stamina();
    bool hit();
};

#endif

