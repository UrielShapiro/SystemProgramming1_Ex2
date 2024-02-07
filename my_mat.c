#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

void inputMatrix(int mat[][MATRIX_SIZE], int n)
{
    for(size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            scanf("%d", &mat[j][i]);
        }
    }
}
int weightOfShortestPath(int mat[][MATRIX_SIZE], int matrix_size, int start, int end)
{
    int distanceMatrix[matrix_size][matrix_size];
    int infinity = 0;
    for(size_t m = 0; m < matrix_size; m++)
    {
        for (size_t l = 0; l < matrix_size; l++)
        {
            distanceMatrix[l][m] = infinity;
        }
    }
    for (size_t i = 0; i < matrix_size; i++)
    {
        for (size_t j = 0; j < matrix_size; j++)
        {
            if(mat[j][i] > 0)
            {
              distanceMatrix[j][i] = mat[j][i];
            }
        }
    }
    for (size_t k = 0; k < matrix_size; k++)
    {
        for (size_t i = 0; i < matrix_size; i++)
        {
            for (size_t j = 0; j < matrix_size; j++)
            {
                if(i != j)
                {
                    if (distanceMatrix[i][j] == infinity || distanceMatrix[i][j] > distanceMatrix[i][k] + distanceMatrix[k][j])
                    {
                        if(distanceMatrix[i][k] > infinity && distanceMatrix[k][j] > infinity)
                        {
                            distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                        }
                    }
                }
            }
        }
    }
    if (distanceMatrix[start][end] == infinity)
    {
        return -1;
    }
    else
    {
        return distanceMatrix[start][end];
    }
}
int ValidPath(int mat[][MATRIX_SIZE], int n, int i, int j)
{
    if(weightOfShortestPath(mat, n, i, j) != -1)
    {
        return TRUE;
    }
    return FALSE;
}