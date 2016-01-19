#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <map>
#include <iomanip>

using namespace std;

void convertToBin(vector<string> &grid) {
  for (int i = 0; i < grid.size(); i++) {
    switch(atoi(grid[i].c_str())) {
      case 0:
        grid[i] = "0000";
        break;
      case 1:
        grid[i] = "0001";
        break;
      case 2:
        grid[i] = "0010";
        break;
      case 3:
        grid[i] = "0011";
        break;
      case 4:
        grid[i] = "0100";
        break;
      case 5:
        grid[i] = "0101";
        break;
      case 6:
        grid[i] = "0110";
        break;
      case 7:
        grid[i] = "0111";
        break;
      case 8:
        grid[i] = "1000";
        break;
      case 9:
        grid[i] = "1001";
        break;
      case 10:
        grid[i] = "1010";
        break;
      case 11:
        grid[i] = "1011";
        break;
      case 12:
        grid[i] = "1100";
        break;
      case 13:
        grid[i] = "1101";
        break;
      case 14:
        grid[i] = "1110";
        break;
      case 15:
        grid[i] = "1111";
        break;
    }
  }
}


int main(int argc, char *argv[]) {
  string observations, filename, ob1, ob2, ob3, ob4;
  double sensoryError;
  int gRowSize = 0, gColSize = 0, tSize = 0;
  vector<string> grid;

  filename = argv[1];
  sensoryError = atof(argv[2]);
  for(int i = 3; i < argc; i++) {
    switch (i) {
      case 3:
        ob1 = argv[i];
        break;
      case 4:
        ob2 = argv[i];
        break;
      case 5:
        ob3 = argv[i];
        break;
      case 6:
        ob4 = argv[i];
        break;
    }
  }

  ifstream inputfile;
  inputfile.open(filename.c_str());

  // initialize grid world
  string entry;
  stringstream ss;

  while (getline(inputfile, entry)) {
    ss.str(entry);
    gColSize = 0;
    while (ss) {
      string tmp;
      if (ss.peek() != '\r' && ss.peek() != '\n' && !ss.eof()) {
        ss >> tmp;
        grid.push_back(tmp);
        gColSize++;
      } else {
        string tmp2;
        ss >> tmp2;
      }
    }
    gRowSize++;
    ss.clear();
  }

  convertToBin(grid);

  double matrixT[gColSize][gRowSize];

  tSize = gColSize * gRowSize;

  for (int i = 0; i < tSize; i++) {
    for (int j = 0; j < tSize; j++) {
      matrixT[i][j] = 0;
    }
  }

  for (int i = 0; i < grid.size(); i++) {
    cout << grid[i] << " ";
  }
  cout << endl;

  /*for (int i = 0; i < grid.size(); i++) {
    //seting up varibables used to init T
    double numOfPos = 0;
    double percent = 1;
    if(grid[i].at(0) == '0') {
      numOfPos++;
    }
    if(grid[i].at(1) == '0') {
      numOfPos++;
    }
    if(grid[i].at(2) == '0') {
      numOfPos++;
    }
    if(grid[i].at(3) == '0') {
      numOfPos++;
    }
    if (numOfPos) {
      percent = 1.0/numOfPos;
      if(grid[i].at(0) == '0') {
        matrixT[i-gColSize][i] = percent;
      }
      if(grid[i].at(1) == '0') {
        matrixT[i+gColSize][i] = percent;
      }
      if(grid[i].at(2) == '0') {
        matrixT[i-1][i] = percent;
      }
      if(grid[i].at(3) == '0') {
        matrixT[i+1][i] = percent;
      }
    }
  }

  for (int i = 0; i < grid.size(); i++) {
    cout << grid[i] << " ";
  }

   //cout << gColSize << " " << tSize << endl;
  for (int i = 0; i < tSize; i++) {
    for (int j = 0; j < tSize; j++) {
      if (j%tSize == 0) {
        cout << endl;
      }
      cout << setw(8) << matrixT[i][j] << " ";
    }
  }


 cout << endl << endl;*/

}
