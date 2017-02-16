//Scot Stolp
//Project 4 "Joust Project" a.k.a "Almost the death of me project"

#include "Weapon.h"
#include "Knight.h"
#include "Random.h"
#include <iostream>
#include <string>
using namespace std;

//Main function
int main()
{
  /*  Weapon w("sword", 3 ,25);
    cout << "im in the constructor" << endl;
    w.display();

    int callStamina;
    callStamina = w.getStamina();
    cout << callStamina << endld*/
    string knight1;
    string knight2;
    int knightStam1;
    int knightStam2;
    string weaponType1;
    string weaponType2;
    int weaponStam1;
    int weaponStam2;
    int weaponHitChance1;
    int weaponHitChance2;

    cout << "What is the first knights name?" << endl;
    getline(cin, knight1);
    cout << "What is the first knights stamina?" << endl;
    cin >> knightStam1;
    cin.ignore();
    cout << "What is the type of weapon that the first knight is using?" << endl;
    getline(cin, weaponType1);
    cout << "What is the weapons stamina required?" << endl;
    cin >> weaponStam1;
    cin.ignore();
    cout << "What is the weapons hit chance?" << endl;
    cin >> weaponHitChance1;
    cin.ignore();
    
    //Variables that are storing info into my Knight #1
    Knight k1(knight1, knightStam1, weaponType1, weaponStam1, weaponHitChance1);

    cout << "What is the second knights name?" << endl;
    getline(cin, knight2);
    cout << "What is the second knights stamina?" << endl;
    cin >> knightStam2;
    cin.ignore();
    cout << "What is the type of weapon that second knight is using?" << endl;
    getline(cin, weaponType2);
    cout << "What is the weapons stamina required?"<< endl;
    cin >> weaponStam2;
    cin.ignore();
    cout << "What is the weapons hit chance?" << endl;
    cin >> weaponHitChance2;
    cin.ignore();

    //Variable that are storing info into my Knight #2
    Knight k2(knight2, knightStam2, weaponType2, weaponStam2, weaponHitChance2);

    while(k1.exhausted() == false && k1.onHorse() == true && k2.exhausted() == false &&          k2.onHorse() == true)
    {
        k1.charge();

        if(k2.onHorse() == true)
            k2.charge();
        else
            k2.onHorse() == false;
        
        k1.display();
        cout << endl;
        k2.display();
        cout << endl;
            
    }


return 0;
}
