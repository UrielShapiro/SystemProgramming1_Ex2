#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_mat.h"

void clearMatrix(int** mat, int n)
{
    for (size_t i = 0; i < n; i++)
    {
         free(mat[i]);
    }
    free(mat);
}

int main()
{
    char choice;
    int** matrix = (int**) malloc(MATRIX_SIZE* sizeof(int));
    for (size_t i = 0; i < MATRIX_SIZE; i++)
    {
        matrix[i] = (int*) malloc(MATRIX_SIZE * sizeof(int));
    }
    
do
{
    scanf("%c", &choice);
    choice = toupper(choice);
  switch (choice)
    {
    case 'A':
        inputMatrix(matrix, MATRIX_SIZE);
        break;
    case 'B':
        printf("Please enter a starting point and an ending point: ");
        int start1,end1;
        scanf("%d %d", &start1 ,&end1);
        ValidPath(matrix, MATRIX_SIZE, start1, end1);
        break;
    case 'C':
        printf("Please enter a starting point and an ending point: ");
        int start2,end2;
        scanf("%d %d", &start2 ,&end2);
        weightOfShortestPath(matrix, MATRIX_SIZE, start2, end2);
        break;
    default:
        break;
    }
} while (choice != 'D' || choice != EOF);

    clearMatrix(matrix, MATRIX_SIZE);
 return 0;
}