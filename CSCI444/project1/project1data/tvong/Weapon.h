#ifndef WEAPON_H
#define WEAPON_H
#include<string>
#include"Random.h" 
#include<iostream>
#include<cstdlib>
using namespace std; 

class Weapon
{
  private: 
    int stamina_required;  
    int hit_chance;
    string name; 

  public: 
    void set(string, int, int); 
    void display(); 
    int get_stamina(); 
    bool hit(); 
}; 
#endif
