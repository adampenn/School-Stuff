//Randell Gallardo
#ifndef WEAPON_H
#define WEAPON_H
#include<iostream>
#include<string>
using namespace std;

class Weapon {
  public:
    void set(string, int, int);
    void display();
    int get_stamina();
    bool hit();

  private:
    int stamina_required,  hit_chance;
    string name;

};
#endif

