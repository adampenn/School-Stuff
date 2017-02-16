// Clemencia Raby
// Project 4
// Knight.cpp

#include "Knight.h"
#include <iostream>

Knight::Knight(string n_n, int n_s, string n_t, int n_hc, int n_sr)
    : n(n_n), s(n_s), w(n_t, n_hc, n_sr)
{}

void Knight::display()
{
    cout << "Knight's Name: " << n << endl;
    cout << "Knight's Stamina: " << s << endl;
    w.display();
}

bool Knight::exhausted()
{
    if (s > 0)
        return false;
    else
        return true;
}

bool Knight::on_horse()
{
    return h;
}

bool Knight::attack()
{
    s = s - w.get_hit_chance();

    if (w.did_you_hit())
        return true;
    else
        return false;
}

void Knight::unhorse()
{
    h = false;
}

int Knight::get_stamina()
{
    return s;
}

string Knight::get_name()
{
    return n;
}
