class Knight {
  private:
    int stamina;
    Weapon weapon_in_hand;
  public:
    void display()
  };

void Weapon::display()
{

  cout << "Chance of hitting: " << hit_chance << endl;
}
void Knight::display()
{
   int x;
   x=5;
   cout << "Stamina: " << stamina;
   x=weapon_in_hand.get_stamina_required();
   weapon_in_hand.display();

   Weapon.display(); //incorrect, because "Weapon" is not an object
   float = 3.14;

}

Knight k1(....);


k1.display();



kkk
