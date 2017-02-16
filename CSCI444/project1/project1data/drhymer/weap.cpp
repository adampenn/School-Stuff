class Weapon {
  private:
    string type;
    //etc.
  public:
    int get_stamina_required(void);
    bool did_you_hit(void);
    void display();
};


bool Weapon::did_you_hit(void)
{
  Random theGenerator(1,100);
  int rn;
  rn=theGenerator.get();
  if(rn<=hit_chance)
    return true;
  else
    return false;
}
