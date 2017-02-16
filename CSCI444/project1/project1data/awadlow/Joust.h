#ifndef JOUST_H
#define JOUST_H
#include<string>
using namespace std;
//DATE CLASS DECLARATION
class Joust {
  public:
    Joust(string yn,string ywn,int yhc,int ysc,int ys,bool ye,bool yuh , string on,string own,int ohc,int osc,int os,bool oe,bool ouh  ); //constructor
    void display_weapon();
    void display_knight();
	void reset_knight();
	void choose_your_weapon();
	void type_your_name();
	void generate_opponent_weapon();
	void pause();
	int judge();
	void round();
	
  private:
	string your_name;
	string your_wname;
	int your_hitchance;
	int your_stamina_cost;
	int your_stamina;
	bool your_exhausted;
	bool your_unhorsed;
	
	string opponent_name;
	string opponent_wname;
	int opponent_hitchance;
	int opponent_stamina_cost;
	int opponent_stamina;
	bool opponent_exhausted;
    	bool opponent_unhorsed;
};
#endif
