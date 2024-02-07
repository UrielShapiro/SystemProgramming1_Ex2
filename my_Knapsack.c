#include <stdio.h>
#define NUM_OF_ITEMS 5
#define BAG_WEIGHT 20
#define NAME_LENGTH (20+1)

//Function to calculate the maximum of two numbers, will be used in the knapSack function
int max(int num1, int num2)
{
    if(num1 > num2)
    {
        return num1;
    }
    return num2;
}
int knapSack(int weights[], int values[], int selected_bool[])
{
    int mat[NUM_OF_ITEMS + 1][BAG_WEIGHT + 1]; //Create a matrix that will hold the maximum value of the items that can be put in the bag
    for (size_t i = 0; i < NUM_OF_ITEMS + 1; i++)
    {
        mat[i][0] = 0;  //Initiate the first column of the matrix to 0
    }
    for (size_t i = 0; i < BAG_WEIGHT + 1; i++)
    {
        mat[0][i] = 0;  //Initiate the first row of the matrix to 0
    }
    for (size_t i = 1; i < NUM_OF_ITEMS + 1; i++)
    {
        for (size_t j = 1; j < BAG_WEIGHT + 1; j++)
        {
            if (weights[i-1] > j)   //If the weight of the item is greater than the weight of that column
            {
                 mat[i][j] = mat[i-1][j];   //Current weight is greater than the weight of the column, 
                 //so the value will be the same as the value of the previous item
            }
            else //If the weight of the item is less than the weight of that column
             {
                //The value of the cell will be the maximum of the value of the previous item 
                //and the value of the current item plus the value of the item that can be put in the bag with the remaining weight
                 mat[i][j] = max(mat[i-1][j], (mat[i-1][j-weights[i-1]] + values[i-1]));
             }
        }
    }
    size_t i = NUM_OF_ITEMS;
    size_t j = BAG_WEIGHT;
    while (i > 0 && j > 0)  //A loop that will go through the matrix and will set the selected items to 1 on the selected_bool array
    {
        if(j < weights[i-1] || mat[i][j] == mat[i-1][j])    //If the weight of the item is greater than the weight of the column
        // or the value of the cell is the same as the value of the previous item
        {
            i--;    //Move to the previous item
        }
        else
        {
            selected_bool[i-1] = 1; //Set the selected item to 1 on the selected_bool array
            j = j - weights[i-1];   //j will be the remaining weight
            i--;                    //Current item was taken. Keep checking on the previous item
        }
        
    }
    return mat[NUM_OF_ITEMS][BAG_WEIGHT];   //Return the maximum value that can be put in the bag which is the value of the last cell in the matrix
}
int main()
{
    int weight[NUM_OF_ITEMS] = {0};
    char items[NUM_OF_ITEMS][NAME_LENGTH];
    int prices[NUM_OF_ITEMS] = {0};
    int selected[NUM_OF_ITEMS] = {0};
    for (size_t i = 0; i < NUM_OF_ITEMS; i++)
    {
        scanf("%s %d %d", items[i], &prices[i], &weight[i]);    //Get the name, price and weight of each item from the user
    }
    int knapSack_weight = knapSack(weight, prices, selected);   //Call the knapSack function and get the maximum value that can be put in the bag
    printf("Maximum profit: %d\n", knapSack_weight);
    printf("Selected items:");
    for (size_t i = 0; i < NUM_OF_ITEMS; i++)
    {
        if (selected[i] == 1)
        {
            printf(" %s", items[i]);    //Print the selected items for a maximum value
        }
    }
}