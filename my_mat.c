#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"
/* 
Function to initiate a matrix using the input from the user
*/
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
/*
Function to calculate the weight of the shortest path between two vertices using the Floyd-Warshall algorithm
*/
int weightOfShortestPath(int mat[][MATRIX_SIZE], int matrix_size, int start, int end)
{
    int distanceMatrix[matrix_size][matrix_size];   //Create a matrix which will hold the shortest distance between each pair of vertices
    for(size_t m = 0; m < matrix_size; m++)
    {
        for (size_t l = 0; l < matrix_size; l++)
        {
            distanceMatrix[l][m] = infinity;    //Initiate the matrix where each vertix has a distance of infinity to each other
        }
    }
    for (size_t i = 0; i < matrix_size; i++)
    {
        for (size_t j = 0; j < matrix_size; j++)
        {
            if(mat[j][i] > 0)   //If there is a connection between the vertices in the original matrix
            {
              distanceMatrix[j][i] = mat[j][i]; //Set the distance between the vertices in the distance matrix to the weight of the connection
            }
        }
    }
    for (size_t k = 0; k < matrix_size; k++)
    {
        for (size_t i = 0; i < matrix_size; i++)
        {
            for (size_t j = 0; j < matrix_size; j++)
            {
                if(i != j)  //Calculate the shortest path only if the vertices are not the same
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
    if (distanceMatrix[start][end] == infinity)    //If there is no connection between the vertices
    {
        return -1;
    }
    else
    {
        return distanceMatrix[start][end];  //Return the weight of the shortest path
    }
}
/*  
Function to check if there is a path between two vertices
*/
int ValidPath(int mat[][MATRIX_SIZE], int n, int i, int j)
{
    if(weightOfShortestPath(mat, n, i, j) != -1)    //If there is a connection between the vertices, weightOfShortestPath will not return -1
    {
        return TRUE;
    }
    return FALSE;
}