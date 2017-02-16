#ifndef KNIGHT_H
#define KNIGHT_H
#include <iostream>
#include <string>
using namespace std;

class Knight
{
  private:
    string name;
    int stam;
    int stamreq;
  public:
    Knight (string name, int stam);
    void gettired(int stamreq);
    int getstam();
};

#endif
