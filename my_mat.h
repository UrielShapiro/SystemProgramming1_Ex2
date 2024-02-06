#define MATRIX_SIZE 10
#ifndef _my_mat_h
#define _my_mat_h
#define TRUE 1          //Will be used as a return value
#define FALSE 0         //Will be used as a return value
//Declerations of the functions that will be used in the main class.
   void inputMatrix(int** mat, int n);
   int weightOfShortestPath(int** mat, int n, int start, int end);
   int ValidPath(int** mat, int n, int i, int j);
#endif