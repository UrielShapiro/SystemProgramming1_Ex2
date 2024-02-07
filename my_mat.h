#define MATRIX_SIZE 10
#ifndef _my_mat_h
#define _my_mat_h
#define TRUE 1          //Will be used as a return value
#define FALSE 0         //Will be used as a return value
//Declerations of the functions that will be used in the main class.
   void inputMatrix(int mat[][MATRIX_SIZE], int n);
   int weightOfShortestPath(int mat[][MATRIX_SIZE], int matrix_size, int start, int end);
   int ValidPath(int mat[][MATRIX_SIZE], int n, int i, int j);
#endif