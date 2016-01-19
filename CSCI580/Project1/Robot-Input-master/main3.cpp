//Adam Penn
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include <bitset>

using namespace std;

int main(int argc, char *argv[]) {
  string filename;
  float sensoryError;
  int gRowSize = 0, gColSize = 0, tSize = 0;
  vector<string> grid;
  vector<string> observations;

  filename = argv[1];
  sensoryError = atof(argv[2]);
  for (int i = 3; i < argc; i++) {
    observations.push_back(argv[i]);
  }

  ifstream inputfile;
  inputfile.open(filename.c_str());

  string entry;
  stringstream ss;
  float acctualStates = 0.0;

  while (getline(inputfile, entry)) {
    ss.str(entry);
    gColSize = 0;
    while (ss) {
      string tmp;
      if (ss.peek() != '\n' && !ss.eof()) {
        ss >> tmp;
        if (tmp != "15") {
          acctualStates++;
        }
        if(tmp != "") {
          grid.push_back(tmp);
          gColSize++;
        }
      } else {
        string tmp2;
        ss >> tmp2;
      }
    }
    gRowSize++;
    ss.clear();
  }
  inputfile.close();

  for (int i = 0; i <grid.size(); i++) {
    switch (atoi(grid[i].c_str())) {
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

  tSize = gColSize*gRowSize;
  float matrixT[tSize][tSize];

  //int to 0
  for (int i = 0; i < tSize; i++) {
    for (int j = 0; j < tSize; j++) {
      matrixT[i][j] = 0;
    }
  }

  /*for (int i = 0; i < grid.size(); i++) {
    if(i%gColSize == 0) {
      cout << endl;
    }
    if (grid[i] == "") {
      cout << setw(6) << "NULL" << " ";
    } else {
      cout << setw(6) << grid[i] << " ";
    }
  }
  cout << endl;*/

  //Initializes our Transitivity Matrix T
  for (int i = 0; i < grid.size(); i++) {
    float numOfPos = 0, percent = 0;
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

    if (numOfPos != 0) {
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
  //cout << "Transitivity Matrix" << endl;
  //Print out Transitivity Matrix T
  /*//Whenever our j counter hits the end of a column, print a new line
  for (int i = 0; i < tSize; i++) {
    for (int j = 0; j < tSize; j++) {
      //Whenever our j counter hits the end of a column, print a new line
      if (j%tSize == 0) {
        cout << endl;
      }
      cout << setw(8) << matrixT[i][j] << " ";
    }
  }
  cout << endl;*/


  //cout << "Joint Probability Matrix" << endl;
  //Initialize Joint Probability matrix J
  float matrixJ[tSize];
  for (int i = 0; i < tSize; i++) {
    //As long as our current element isn't a blocked grid point
    if (grid[i] != "1111") {
      matrixJ[i] = 1.0/acctualStates;
    } else {
      matrixJ[i] = 0;
    }
  }
  //Print Joint Probability Matrix
  /*for (int i = 0; i < tSize; i++) {
    cout << setw(8) << matrixJ[i] << endl;
  }
  cout << endl;*/

  //cout << "Z Matrix" << endl;
  //Initialize Z matrix Z
  float matrixZ[tSize];
  for (int i = 0; i < tSize; i++) {
    matrixZ[i] = 0;
    for (int j = 0; j < tSize; j++) {
      if (grid[i] != "1111") {
        matrixZ[i] += matrixT[i][j]*matrixJ[j];
      }
    }
  }
  /*
  //Print Z Matrix Z
  for (int i = 0; i < tSize; i++) {
    cout << setw(8) << matrixZ[i] << endl;
  }
  cout << endl;*/

  //cout << "Joint Probability Matrix 1" << endl;
  //Copy Joint Probability Matrix from Z
  for (int i = 0; i < tSize; i++) {
    matrixJ[i] = 0;
    matrixJ[i] = matrixZ[i];
  }
  /*//Print Joint Probability Matrix J
  for (int i = 0; i < tSize; i++) {
    cout << setw(8) << matrixJ[i] << endl;
  }
  cout << endl;*/

  //cout << "Error Matrix" << endl;
  //Initialize Error Matrix
  float matrixD[tSize];
  for (int i = 0; i < 5; i++) {
    matrixD[i] = (pow(sensoryError,i))*(pow((1-sensoryError),(4-i)));
  }
  /*//Print Error Matrix
  for (int i = 0; i < 5; i++) {
    cout << setw(8) << matrixD[i] << " ";
  }
  cout << endl;*/


  //Begin Robot Localization Loop
  float matrixO[tSize][tSize];
  float matrixY[tSize];
  float matrixE[tSize];
  for (int theTime = 3; theTime < argc; theTime++) {
    //Determine binary representation of the given time's obstacles
    bitset<4> input;
    //Searches a string for a given substring, in this case N S W or E
    if (strstr(argv[theTime], "N") != NULL){
      input[3] = 1;
    }
    if (strstr(argv[theTime], "S") != NULL){
      input[2] = 1;
    }
    if (strstr(argv[theTime], "W") != NULL){
      input[1] = 1;
    }
    if (strstr(argv[theTime], "E") != NULL){
      input[0] = 1;
    }
    string startObstacles;
    startObstacles = input.to_string();

    for (int i = 0; i < tSize; i++) {
      matrixY[i] = 0;
      matrixE[i] = 0;
      for (int j = 0; j < tSize; j++) {
        matrixO[i][j] = 0;
      }
    }

    //Initialize Observation Matrix O
    //cout << "O Matrix at time " << theTime-2 <<  endl;
    for (int i = 0; i < tSize; i++) {
      //Initialize Observation Matrix O
        int numOfPos = 0, percent = 0;

        //Compares current time's obstacles to current state (i)
        if(grid[i].at(0) != startObstacles.at(0)) {
          numOfPos++;
        }
        if(grid[i].at(1) != startObstacles.at(1)) {
          numOfPos++;
        }
        if(grid[i].at(2) != startObstacles.at(2)) {
          numOfPos++;
        }
        if(grid[i].at(3) != startObstacles.at(3)) {
          numOfPos++;
        }
        //Sets Observation at state 0 to the error matrix based on the
        //difference between current times obstacles and current state (i)
        matrixO[i][i] = matrixD[numOfPos];
        //cout << setw(8) << matrixO[i][i] << " " ;
    }
    //cout << endl;

    //Initialize Y Matrix
    //cout << "Y Matrix at time " << theTime-2 <<  endl;
    for (int i = 0; i < tSize; i++) {
      matrixY[i] = 0;
      for (int j = 0; j < tSize; j++) {
        if (grid[i] != "1111") {
          matrixY[i] += matrixO[i][j]*matrixJ[j];
        }
      }
    }
    //Print Y Matrix
    for (int i = 0; i < tSize; i++) {
      //cout << setw(8) << matrixY[i] << " ";
    }
    //cout << endl;

    //Initialize J Matrix
    //cout << "J Matrix at time " << theTime-2 <<  endl;
    for (int i = 0; i < tSize; i++) {
      matrixJ[i] = 0;
      for (int j = 0; j < tSize; j++) {
        if (grid[i] != "1111") {
          matrixJ[i] += matrixT[i][j]*matrixY[j];
        }
      }
    }
    //Print Y Matrix
    for (int i = 0; i < tSize; i++) {
      //cout << setw(8) << matrixJ[i] << " ";
    }
    //cout << endl;

  } //End Robot Localization Loop

  //Initialize E Matrix
  //Calculate sum of Y
  //cout << "E Matrix at time " << argc-2 << endl;
  float sum = 0.0;
  for (int i = 0; i < tSize; i++){
    sum += matrixY[i];
  }
  for (int i = 0; i < tSize; i++){
    matrixE[i] = matrixY[i]/sum;
    //cout << setw(8) << matrixE[i] << " ";
  }
  //cout << endl;

  //Find largest value or values in E Matrix
  float maxValue = 0.0;
  for (int i = 0; i < tSize; i++){
    if(matrixE[i] > maxValue){
      maxValue = matrixE[i];
    }
  }
  float endWorld[gRowSize][gColSize];
  int index = 0;
  for(int i = 0; i < gRowSize; i++){
    for(int j = 0; j < gColSize; j++){
      endWorld[i][j] = 0;
      endWorld[i][j] = matrixE[index];
      index++;
    }
  }

  // for(int i = 0; i < gRowSize; i++){
  //   for(int j = 0; j < gColSize; j++){
  //     cout << setw(6)<<endWorld[i][j] << " ";
  //   }
  // }

  index = 0;
  for(int i = 0; i < gRowSize; i++){
    for(int j = 0; j < gColSize; j++){
      if(endWorld[i][j] == maxValue){
        cout << "(" << i << ", " << j << ") - ";
        cout << matrixE[index] << endl;
      }
      index++;
    }
  }
}
