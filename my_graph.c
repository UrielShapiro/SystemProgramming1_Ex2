#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_mat.h"

int main()
{
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    char choice;
do  //A loop that will get char input from the user and will call the relevant function untill the user will enter 'D' or EOF
{
    choice = getchar();
    switch (choice)
    {
    case 'A':
        inputMatrix(matrix, MATRIX_SIZE);   //Call the function that will initiate the matrix
        break;
    case 'B':
        int start1,end1;
        scanf("%d %d", &start1 ,&end1); //Get the start and end vertices from the user
        int ans = ValidPath(matrix, MATRIX_SIZE, start1, end1); //Call the function that will check if there is a path between the vertices
        if (ans > 0)    //If there is a path
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
        scanf("%d %d", &start2 ,&end2); //Get the start and end vertices from the user
        printf("%d\n",weightOfShortestPath(matrix, MATRIX_SIZE, start2, end2)); //Call the function that will calculate the weight of the shortest path between the vertices
        break;
    default:
        break;
    }
} while (choice != 'D' && choice != EOF);
 return 0;
}