#include <iostream>
#include <iomanip>

            


class Knight
{
    private:
    int stam;
    string name;
    bool on_horse;
    Weapon weapon_in_hand;

    public:
    bool pass();
    void unhorse();
    bool exhausted();
    bool onhorse();
    void display();
    void set(string n, int s, string t, int sr, int hc)

    {
        name=n;
        stam=s;
        weapon_in_hand.set(t,sr,hc);
        on_horse=true;
    }

};

class kn1
{
stam= 67
stam_required=10
hit = 45


}

class kn2
{
stam=58
stam_required=30
hit=79
}
