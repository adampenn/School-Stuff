//Shandra Flatley
//File: main file
#include "weapons.h"
#include "knight.h"
#include "Random.h"
#include <iostream>


using namespace std;

int main()
{
    string knight1;
    string kt1weapon;
    int knight1stam;
    int knight1htchance;
    int staminacost;
    
    Knight kn1, kn2;
    //max is 100 for all integer variables
    cout << "Name of knight one?" << endl;
    getline(cin, knight1);
    cout << "The stamina of " << knight1 << ":" << endl;
    cin >> knight1stam;
    
    cout << knight1 << "'s weapon?" << endl;
    cin.ignore();
    getline(cin, kt1weapon);
    
    cout << "Stamina required for " << kt1weapon << ":" << endl;
    cin >> staminacost;
    
    cout << "The hit chance of " << knight1 << "?" << endl;
    cin >> knight1htchance;
    
    kn1.set(knight1, knight1stam, kt1weapon, staminacost, knight1htchance); //seting variables to implement in knight.cpp/h
    
    string knight2;
    string kt2weapon;
    int knight2stam;
    int knight2htchance;
    int staminacost2;
    cin.ignore();
    cout << "Name of knight two?" << endl;
    getline(cin, knight2);
    
    cout << "The stamina of " << knight2 << ":" << endl;
    cin >> knight2stam;
    
    cout << knight2 << "'s weapon?" << endl;
    cin.ignore();
    getline(cin, kt2weapon);
   
    
    cout << "Stamina required for " << kt2weapon << ":" << endl;
    cin >> staminacost2;
    
    cout << "The hit chance of " << knight2 << "?" << endl;
    cin >> knight2htchance;
    
    kn2.set(knight2, knight2stam, kt2weapon, staminacost2, knight2htchance);
    cout << endl;
    int i=1;
    do //loop for the jousting rounds until one knight wins, exhaustion or knocked off horse
    {
        cout<<"Joust round: "<< i <<endl;
        cout << endl;
        if(kn1.attack())
            kn2.unhorsed();
        if(kn2.attack())
            kn1.unhorsed();
        
        kn1.display();
        cout<<endl<<endl;
        kn2.display();
        
        i++;
        cout << endl;
    }while(!kn1.exhausted() && kn1.onhorse() && !kn2.exhausted() && kn2.onhorse());
    
    if(kn1.exhausted() || !kn1.onhorse())
    {
        cout << knight2 << " is victorious!" << endl;
    }
    else
    {
        cout << knight1 << " is victorious!" << endl;
    }
    
    return 0;
    
}

