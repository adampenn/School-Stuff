#include <iostream>
#include "Weapon.h"
#include "Knight.h"
#include "Random.h"
using namespace std;
int main()
{
    string k1_name, k2_name, w1_type, w2_type;
    int k1_stamina, k2_stamina;
    int w1_hc, w2_hc;
    int w1_sr, w2_sr;

    cout << endl;
    cout << "What is your name Sir?" << endl;
    cin >> k1_name;
    cout << "And what level is your stamina " << k1_name << "?" << endl;
    cin >> k1_stamina;
    cout << "Excellent! What weapon do you have with you today?" << endl;
    cin >> w1_type;
    cout << "Sounds dangerous. What is the likelihood of you striking an opponent with that? (1-100)" << endl;
    cin >> w1_hc;
    cout << "How much stamina does it take to use your " << w1_type << "?" << endl;
    cin >> w1_sr;

    cout << endl;
    cout << "What is your opponents name?" << endl;
    cin >> k2_name;
    cout << "What is the level of " << k2_name << "s stamina?" << endl;
    cin >> k2_stamina;
    cout << "Nice! What weapon will he be using today?" << endl;
    cin >> w2_type;
    cout << "That also sounds dangerous! What is the likelihood that " << k2_name << " will hit you?(1-100)" << endl;
    cin >> w2_hc;
    cout << "How much stamina will that take?" << endl;
    cin >> w2_sr;
    cout << endl;

    Knight k1(k1_name, k1_stamina, w1_type, w1_sr, w1_hc);
    Knight k2(k2_name, k2_stamina, w2_type, w2_sr, w2_hc);


    k1.display();
    k2.display2();
    cout<<endl;

    while (k1.exhausted()==false && k2.exhausted()==false && k1.on_horse==true && k2.on_horse==true)
    {
        bool hit;

        hit=k1.attack();
        if(hit==true)
            k2.unhorse();

        hit=k2.attack();
        if(hit==true)
            k1.unhorse();

        k1.display();
        k2.display2();
    }

}
