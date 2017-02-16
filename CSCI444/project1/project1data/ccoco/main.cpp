/*
** project4
** 		The test program for the
** 		new game that the company is designing
** Christy Coco
** main.cpp
*/

#include<iostream>
#include "Knight.h"

int main(){
    int stamina, hit_chance, stamina_req;
    string name, type;
    cout<<"What is first knight's name?"<<endl;
    getline(cin, name);
    cout<<"What is the stamina for first knight?"<<endl;
    cin >> stamina;
    cin.ignore();
    cout<<"What type of weapon dose first knight have?"<<endl;
    getline(cin, type);
    cout<<"What is the hit chance for this weapon?"<<endl;
    cin >> hit_chance;
    cin.ignore();
    cout<<"What is the stamina required for using this weapon?"<<endl;
    cin >> stamina_req;
    cin.ignore();
    Knight k1(name, stamina, type, hit_chance, stamina_req);
    cout<<"What is second knight's name?"<<endl;
    getline(cin, name);
    cout<<"What is the stamina for second knight?"<<endl;
    cin >> stamina;
    cin.ignore();
    cout<<"What type of weapon dose second knight have?"<<endl;
    getline(cin, type);
    cout<<"What is the hit chance for this weapon?"<<endl;
    cin >> hit_chance;
    cin.ignore();
    cout<<"What is the stamina required for using this weapon?"<<endl;
    cin >> stamina_req;
    cin.ignore();
    Knight k2(name, stamina, type, hit_chance, stamina_req);
    
    int counter=1;
    while(!k1.are_you_exhausted() && k1.are_you_on_horse()
        && !k2.are_you_exhausted() && k2.are_you_on_horse()){
        	
        	cout<<"Round number "<<counter<<endl;
        	bool k1_hit = k1.charge();
        	bool k2_hit = k2.charge();
        	if (k1_hit || k2.are_you_exhausted())
            	k2.unhorse_yourself();
        	if (k2_hit || k1.are_you_exhausted())
            	k1.unhorse_yourself();
        	counter+=1;
        	k1.display();
        	k2.display();
            cout<<"-----------------------------------------------------------"<<endl<<endl;
    }
}
