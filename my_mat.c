#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

void inputMatrix(int** mat, int n)
{
    for(size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            scanf("%d", &mat[j][i]);
        }
    }
}
int weightOfShortestPath(int** mat, int n, int start, int end)
{
    int** distanceMatrix = (int**) malloc(n * sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        distanceMatrix[i] = (int*) malloc(n * sizeof(int));
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (i == j)
            {
                distanceMatrix[j][i] = 0;
            }
            else
            {
              distanceMatrix[j][i] = mat[j][i];
            }
        }
    }
    for (size_t k = 0; k < n; k++)
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (distanceMatrix[i][j] > distanceMatrix[i][k] + distanceMatrix[k][j])
                {
                    distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                }
            }
            
        }
    }
    if (distanceMatrix[start][end] == 0)
    {
        return -1;
    }
    else
    {
        return distanceMatrix[start][end];
    }
}
int ValidPath(int** mat, int n, int i, int j)
{
    if (mat[i][j] == 0)
    {
        return FALSE;
    }
    
    if(weightOfShortestPath(mat, n, i, j) > 0)
    {
        return TRUE;
    }
    return FALSE;
}
