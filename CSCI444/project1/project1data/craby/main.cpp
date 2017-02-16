// Clemencia Raby
// Project 4
// main.cpp

#include "Knight.h"
#include <iostream>

using namespace std;

int main()
{
    string k1_n;
    string k2_n;
    string k1_w;
    string k2_w;
    int k1_s;
    int k2_s;
    int k1_w_hc;
    int k2_w_hc;
    int k1_w_sr;
    int k2_w_sr;

    cout << "Name of k1: ";
    getline(cin, k1_n);
    cout << "k1 stamina: ";
    cin >> k1_s;
    cin.ignore();
    cout << "k1 weapon: ";
    getline(cin, k1_w);
    cout << "k1 weapon hit chance: ";
    cin >> k1_w_hc;
    cin.ignore();
    cout << "k1 weapon stamina required: ";
    cin >> k1_w_sr;
    cin.ignore();

    cout << "Name of k2: ";
    getline(cin, k2_n);
    cout << "k2 stamina: ";
    cin >> k2_s;
    cin.ignore();
    cout << "k2 weapon: ";
    getline(cin, k2_w);
    cout << "k2 weapon hit chance: ";
    cin >> k2_w_hc;
    cin.ignore();
    cout << "k2 weapon stamina required: ";
    cin >> k2_w_sr;
    cin.ignore();

    Knight k1(k1_n, k1_s, k1_w, k1_w_sr, k1_w_hc);
    Knight k2(k2_n, k2_s, k2_w, k2_w_sr, k2_w_hc);

    cout << endl;
    cout << "Players" << endl;
    k1.display();
    cout << endl;
    k2.display();
    cout << endl;

    for (int round = 1; !k1.exhausted() && !k2.exhausted() && 
            k1.on_horse() && k2.on_horse(); round++)
    {
        cout << "ROUND < < " << round << " > >" << endl;

        cout << k1.get_name() << " and " << k2.get_name()
            << " charge at each other with their weapons..." << endl;

        cout << k1.get_name() << " tries to hit " << k2.get_name()
            << " with his weapon." << endl;
        cout << k2.get_name() << " tries to hit " << k1.get_name()
            << " with his weapon." << endl;

        if (k1.attack())
        {
            cout << k1.get_name() << " hits " << k2.get_name() 
                << " and knocks him off his horse!" << endl;
            k2.unhorse();
        }
        else
            cout << k1.get_name() << " misses!" << endl;

        if (k2.attack())
        {
            cout << k2.get_name() << " hits " << k1.get_name() 
                << " and knocks him off his horse!" << endl;
            k1.unhorse();
        }
        else
            if (k2.on_horse())
                cout << k2.get_name() <<  " misses!" << endl;

        if (k1.exhausted())
            cout << k1.get_name() << " falls off horse due to"
               << " exhaustion!" << endl;
        if (k2.exhausted())
            cout << k2.get_name() << " fals off horse due to"
                <<" exhaustion!" << endl;

        cout << endl;

        if (!k1.exhausted() && k1.on_horse())
            cout << k1.get_name() << " has " << k1.get_stamina()
                << " stamina." << endl;
        
        if (!k2.exhausted() && k2.on_horse())
            cout << k2.get_name() << " has " << k2.get_stamina()
                << " stamina." << endl;

        cout << endl;
    }

    if (!k1.exhausted() && k1.on_horse())
    {
        if (k2.exhausted() || !k2.on_horse())
            cout << k1.get_name() << " is the winner!" << endl;
    } else if (!k2.exhausted() && k2.on_horse())
    {
        if (k1.exhausted() || !k1.on_horse())
            cout << k2.get_name() << " is the winner!" << endl;
    } else
    {
        cout << k1.get_name() << " and " << k2.get_name() << " tied!"
            << endl;;
    }

    return 0;
}
