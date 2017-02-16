/*
Gwyn Polizzi

Joust Project 4

11/12/15
*/

#include"Weapon.h"
#include"Knight.h"
#include"Random.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;


int main()
{

    
    //Question Variables
    string knightName1;
    string knightName2;
    string weaponName1;
    string weaponName2;
    int knightStamina1;
    int knightStamina2;
    int weaponStaminaRequired1;
    int weaponStaminaRequired2;
    int weaponHitChance1;
    int weaponHitChance2;

    
    //Questions Knight 1
    cout << "Please input the information for the first Knight." << endl;
    cout << "What is the first knight's name?" << endl;
    getline(cin, knightName1);
    cout << "What is the first knight's stamina?" << endl;
    cin >> knightStamina1;
    cout << "What is the type of weapon that the knight is using?" << endl;
    cin.ignore();
    getline(cin, weaponName1);
    cout << "What is that weapon's stamina required?" << endl;
    cin >> weaponStaminaRequired1;
    cout << "What is that weapon's hit chance?" << endl;
    cin >> weaponHitChance1;
    cout << endl << endl;
    
    Knight k1(knightName1, knightStamina1, weaponName1, weaponStaminaRequired1, weaponHitChance1); 
    
    
    //Questions Knight 2
    cout << "Please input the information for the second Knight." << endl;
    cout << "What is the second knight's name?" << endl;
    cin.ignore();
    getline(cin, knightName2);
    cout << "What is the second knight's stamina?" << endl;
    cin >> knightStamina2;
    cout << "What is the type of Weapon that the knight is using?" << endl;
    cin.ignore();
    getline(cin, weaponName2);
    cout << "What is the weapon's stamina required?" << endl;
    cin >> weaponStaminaRequired2;
    cout << "What is that weapon's hit chance?" << endl;
    cin >> weaponHitChance2;
    
    Knight k2(knightName2, knightStamina2, weaponName2, weaponStaminaRequired2, weaponHitChance2);

    cout << endl;

while(k1.areYouOnHorse()==true && k1.exhausted()==false && k2.areYouOnHorse()==true && k2.exhausted()==false)
{
    
    k1.charge();

    if(k2.areYouOnHorse() == true)
        k2.charge();
    else
        k2.areYouOnHorse()==false;
    
    k1.display();
    cout << endl;
    k2.display();
}


    return 0;
}
