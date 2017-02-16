#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;


class Lion {
  public:
    Lion(string tp, bool nt, float wt);
    void display();
  private:
    string type;
    bool has_teeth;
    float weight;
};

class Cage {
  private:
    Lion occupantA;
    Liger occupantB;
    Tiger occupantC;
    int width;
    int length;
  public:
    Cage(int w, int l, string type, bool ht, int wt);
    void display();
};
Knight::Knight(....., .....) :......, on_horse(true)

Cage::Cage(int w, int l, string type, bool ht, int wt) 
  : occupantA(...), occupantB(...), occupantC(...), width(...), length(...)
  : occupant(type, ht, wt), width(w), length(l)
{
}

void Cage::display()
{
  occupant.display();
}

class Elephant {
  public:
    void display();
};

void Elephant::display()
{
}

void Lion::display()
{
  cout << "LION" << endl;
  cout << "----" << endl;
  cout << "Type: " << type << endl;
  string answer;
  answer = (has_teeth == true) ? "Yes" : "No"; //ternary operator
  cout << "Teeth: "  << answer << endl;
  cout << "Weight: " << weight << endl;

//  if(has_teeth==true)
//    answer="Yes";
//  else
//    answer="No";
}

Lion::Lion(string tp, bool nt, float wt)
{
  type=tp;
  has_teeth=nt;
  weight=wt;
}

int main()
{
  //Cage::Cage(int w, int l, string type, bool ht, int wt) 
  Cage cg(3, 20, "Growly", true, 3000);

  Lion larry("Grizzly", false, 30);

//  larry.set("Grizzly", false, 30);
  larry.display();
}
