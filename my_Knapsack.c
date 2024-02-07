#include <stdio.h>
#define NUM_OF_ITEMS 5
#define BAG_WEIGHT 20
#define NAME_LENGTH (20+1)

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
    int mat[NUM_OF_ITEMS + 1][BAG_WEIGHT + 1];
    for (size_t i = 0; i < NUM_OF_ITEMS + 1; i++)
    {
        mat[0][i] = 0;
    }
    for (size_t i = 0; i < BAG_WEIGHT + 1; i++)
    {
        mat[i][0] = 0;
    }
    for (size_t i = 1; i < BAG_WEIGHT + 1; i++)
    {
        for (size_t j = 1; j < NUM_OF_ITEMS + 1; j++)
        {
            if (weights[i] > j)
            {
                 mat[i][j] = mat[i-1][j];
            }
             else
             {
                 mat[i][j] = max(mat[i-1][j], mat[i-1][j-weights[i]] + values[i]);
             }
        }
    }
    size_t i = NUM_OF_ITEMS;
    size_t j = BAG_WEIGHT;
    while (i > 0 && j > 0)
    {
        if(mat[i][j] == mat[i-1][j])
        {
            i--;
        }
        else
        {
            selected_bool[i] = 1;
            i--;
            j = j - weights[i];
        }
    }
    return mat[NUM_OF_ITEMS][BAG_WEIGHT];
}
int main()
{
    int weight[NUM_OF_ITEMS];
    char items[NUM_OF_ITEMS][NAME_LENGTH];
    int prices[NUM_OF_ITEMS];
    int selected[NUM_OF_ITEMS] = {0};
    for (size_t i = 0; i < NUM_OF_ITEMS; i++)
    {
        scanf("%s %d %d", items[i], &prices[i], &weight[i]);
    }
    int knapSack_weight = knapSack(weight, prices, selected);
    printf("Maximum profit: %d\n", knapSack_weight);
    printf("Selected items: ");
    for (size_t i = 0; i < NUM_OF_ITEMS; i++)
    {
        if (selected[i] == 1)
        {
            printf("%d", selected[i]);
        }
    }
}

