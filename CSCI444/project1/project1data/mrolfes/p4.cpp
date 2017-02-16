// Name: Mayola Rolfes
// Course: CSCI 111
// Date: 11/11/15
// Assignment: Project 4
// Filename: main.cpp

#include "knight.h"
#include <iostream>
using namespace std;

int main()
{
    string knight_name;
    int knight_stamina;
    string weapon_name;
    int weapon_stamina_required;
    int weapon_hit_chance;

    cout << "Welcome to Joust." << endl << endl;

    cout << "Knight #1's name: ";
    getline(cin, knight_name);
    cout << knight_name << "'s stamina: ";
    cin >> knight_stamina;
    cin.ignore();
    cout << knight_name << "'s weapon: ";
    getline(cin, weapon_name);
    cout << weapon_name << "'s stamina required: ";
    cin >> weapon_stamina_required;
    cin.ignore();
    cout << weapon_name << "'s hit chance: ";
    cin >> weapon_hit_chance;
    cin.ignore();

    Knight knight1(knight_name, knight_stamina, weapon_name, 
            weapon_stamina_required, weapon_hit_chance);

    cout << endl;

    cout << "Knight #2's name: ";
    getline(cin, knight_name);
    cout << knight_name << "'s stamina: ";
    cin >> knight_stamina;
    cin.ignore();
    cout << knight_name << "'s weapon: ";
    getline(cin, weapon_name);
    cout << weapon_name << "'s stamina required: ";
    cin >> weapon_stamina_required;
    cin.ignore();
    cout << weapon_name << "'s hit chance: ";
    cin >> weapon_hit_chance;
    cin.ignore();

    Knight knight2(knight_name, knight_stamina, weapon_name, 
            weapon_stamina_required, weapon_hit_chance);

    cout << knight1.get_name()
        << "\nStamina: " << knight1.get_stamina()
        << "\nWeapon: " << knight1.get_weapon_in_hand().get_name()
        << "\n" << knight1.get_weapon_in_hand().get_name()
        << "'s stamina required: " 
        << knight1.get_weapon_in_hand().get_stamina_required()
        << "\n" << knight1.get_weapon_in_hand().get_name()
        << "'s hit chance: "
        << knight1.get_weapon_in_hand().get_hit_chance()
        << endl;

    cout << knight2.get_name()
        << "\nStamina: " << knight2.get_stamina()
        << "\nWeapon: " << knight2.get_weapon_in_hand().get_name()
        << "\n" << knight2.get_weapon_in_hand().get_name()
        << "'s stamina required: " 
        << knight2.get_weapon_in_hand().get_stamina_required()
        << "\n" << knight1.get_weapon_in_hand().get_name()
        << "'s hit chance: "
        << knight2.get_weapon_in_hand().get_hit_chance()
        << endl;

    int round = 1;

    while ((!knight1.are_you_exhausted() && 
            knight1.are_you_on_your_horse()) &&
            (!knight2.are_you_exhausted() &&
              knight2.are_you_on_your_horse())) {

        if ((!knight1.are_you_exhausted() && 
                    knight1.are_you_on_your_horse()) &&
                (!knight2.are_you_exhausted() &&
                 knight2.are_you_on_your_horse())) {
            cout << "\nRound " << round << endl << endl;
            
            cout << knight1.get_name() << " attacks "
                << knight2.get_name() << " with his " 
                << knight1.get_weapon_in_hand().get_name() << " and ";

            if (knight1.attack()) {
                cout << "hits him!" << endl;
                knight2.unhorse();
            } else
                cout << "misses him!" << endl;

            if ((!knight2.are_you_exhausted() &&
                    knight2.are_you_on_your_horse()) &&
                    !knight1.are_you_exhausted()) {
                cout << knight2.get_name() << " attacks "
                    << knight1.get_name() << " with his "
                   << knight2.get_weapon_in_hand().get_name() 
                   << " and "; 
                
                if (knight2.attack()) {
                    cout << "hits him!" << endl;
                    knight1.unhorse();
                } else
                    cout << "misses him!" << endl;
            }
        }
        
        cout << endl;
        knight1.display();
        cout << endl;
        knight2.display();

        round++;
    }

    cout << endl;

    if (!knight1.are_you_exhausted() &&
            knight1.are_you_on_your_horse()) {
        if (knight2.are_you_exhausted() || 
                !knight2.are_you_on_your_horse())

            cout << knight1.get_name() << " wins!" << endl;

    } else if (!knight2.are_you_exhausted() &&
            knight2.are_you_on_your_horse()) {
        if (knight1.are_you_exhausted() ||
                !knight1.are_you_on_your_horse())

            cout << knight2.get_name() << " wins!" << endl;

    } else
        cout << "It was a tie!" << endl;

    return 0;
}
