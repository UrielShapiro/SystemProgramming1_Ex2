#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_mat.h"

int main()
{
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    char choice;
do
{
    choice = getchar();
    switch (choice)
    {
    case 'A':
        inputMatrix(matrix, MATRIX_SIZE);
        break;
    case 'B':
        int start1,end1;
        scanf("%d %d", &start1 ,&end1);
        int ans = ValidPath(matrix, MATRIX_SIZE, start1, end1);
        if (ans > 0)
        {
            printf("True\n");
        }
        else
        {
            printf("False\n");
        }
        break;
    case 'C':
        int start2,end2;
        scanf("%d %d", &start2 ,&end2);
        printf("%d\n",weightOfShortestPath(matrix, MATRIX_SIZE, start2, end2));
        break;
    default:
        break;
    }
} while (choice != 'D' && choice != EOF);
 return 0;
}