#include <iostream>

using namespace std;

class Weapon
{
    private:
    string name;
    int stam_required, hit;

    Public:
    void set (string, int, int);
    bool hit();
    void display();
    int get_stam();
};
