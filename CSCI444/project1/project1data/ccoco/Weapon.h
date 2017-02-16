/*
** project4
** 		The weapon class declaration
** Christy Coco
** Weapon.h
*/

#ifndef WEAPON_H
#define WEAPON_H
using namespace std;

class Weapon{
    private:
    	string type;
    	int hit_chance;
        int stamina_required;
	public:
        Weapon(string,int,int);
        int get_stamina_required(void);
        bool did_you_hit(void);
        void display(void);
};
             
#endif
