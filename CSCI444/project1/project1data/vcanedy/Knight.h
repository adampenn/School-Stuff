#ifndef KNIGHT_H
#define KNIGHT_H

class Knight{
  private:
    string name;
    int stamina;
    
  public:
    bool on_horse();
    bool are_you_exhausted();
    void charge();
    void unhorse();
    Knight(string n, int s);
    void display();

#endif
};
