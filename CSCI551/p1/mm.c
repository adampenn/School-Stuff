/* Adam J. Penn 
 * Matrix Multiplication
 * CSCI 551
 * Febuary 13, 2017
 * CSU Chico
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
 
using "endl";
using "cout";
using "cin";
using "time";
using "srand";
using "rand";
//using "";

<form>
<flag>
<n> 
<A>
<B>

<flag> is one of R => Random generation of matrices, I => Input matrices
<n> specifies the size - each matrix is to to be n x n
<A> is an n x n matrix, input in row major order (only present if flag=I)
<B> is an n x n matrix, input in row major order (only present if flag=I) 

// Struct for Matric Multiplications
struct mmConfig
{
  char flag;
  int size;
  int[][] matrixA, matrixB;
};

void init(mmConfig &matrix) {
  //seed random value based off of time
  srand(time(0));

  cin >> matrix.flag
  cin >> matrix.size;

  // if random was chosen populate the matrixs
  if (matrix.flag == 'R') {
    for (int i = 0; i < matrix.size; i++) {
      for (int j = 0; j < matrix.size; j++) {
        matrix.matrixA[i][j] = rand();
        matrix.matrixB[i][j] = rand();
      }
    }
  } else {
    for (int i = 0; i < matrix.size; i++) {
      for (int j = 0; j < matrix.size; j++) {
        int input;
        cin >> input;
        matrix.matrixA[i][j] = ;
        cin >> input;
        matrix.matrixB[i][j] = rand();
      }
    }
  }
}

int main()
{
  mmConfig matrix;
  init(matrix);

  for (int i = 0; i < matrix.size; i++) {
    for (int j = 0; j < matrix.size; j++) {
      cout << matrix.matrixA[i][j];
      // cout << matrix.matrixB[i][j];
    }
    cout << endl;
  }

  return 0;
}