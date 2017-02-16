//name: Trang Greaver
//file: project4.cpp
#include "Knight.h"
#include <iostream>
using namespace std;

int main()
{
    string name = "";
    int stamina = 0;
    string type = "";
    int stamina_req = 0;
    int hit_chance = 0;

    cout << "What is your name? ";
    getline(cin, name);

    cout << "What is your stamina? ";
    cin >> stamina;
    cin.ignore();

    cout << "What type is your weapon? ";
    getline(cin, type);

    cout << "How much stamina is required for your weapon? ";
    cin >> stamina_req;
    cin.ignore();

    cout << "What is the hit chance of your weapon? ";
    cin >> hit_chance;
    cin.ignore();

    Knight first_knight(name, stamina, type, stamina_req, hit_chance);


    cout << "What is your opponent's name? ";
    getline(cin, name);

    cout << "What is your opponent's stamina? ";
    cin >> stamina;
    cin.ignore();

    cout << "What type is your opponent's weapon? ";
    getline(cin, type);

    cout << "How much stamina is required for your opponent's weapon? ";
    cin >> stamina_req;
    cin.ignore();

    cout << "What is the hit chance of your opponent's weapon? ";
    cin >> hit_chance;
    cin.ignore();

    Knight second_knight(name, stamina, type, stamina_req, hit_chance);

    cout << endl;
    first_knight.display();
    cout << endl;
    second_knight.display();
    cout << endl;

    while (((first_knight.are_you_exhausted() == false) && (first_knight.are_you_on_your_horse() == true)) && ((second_knight.are_you_exhausted() == false) && (second_knight.are_you_on_your_horse() == true)))
    {
        if (first_knight.attack() == true)
        {
            second_knight.unhorse();
            cout << first_knight.get_name() << " attacks " << second_knight.get_name() << " and " << second_knight.get_name() << " falls off of his horse." << endl;
        }
        else
        {
            cout << first_knight.get_name() << " attacks " << second_knight.get_name() << " and he misses him." << endl;
        }

        if (second_knight.attack() == true)
        {
            first_knight.unhorse();
            cout << second_knight.get_name() << " attacks " << first_knight.get_name() << " and " << first_knight.get_name() << " falls off of his horse." << endl;
        }
        else
        {
            cout << second_knight.get_name() << " attacks " << first_knight.get_name() << " and he misses him." << endl;
        }
        cout << endl;
        first_knight.display();
        second_knight.display();
        cout << "------------------------------" << endl;
    }

    if (first_knight.are_you_exhausted() == true)
    {
        cout << first_knight.get_name() << " is exhausted." << endl;
    }

    if (second_knight.are_you_exhausted() == true)
    {
        cout << first_knight.get_name() << " is exhausted." << endl;
    }

    return 0;
}
