#include <stdio.h>
#define ROWS 3
#define COLS 3

int main()
{
    int matrix[ROWS][COLS];
    int transpose[COLS][ROWS];

    printf("Add Elements in the Matrix\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("Original Matrix:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("The Transpose of the Matrix is:\n");
    for (int j = 0; j < COLS; j++)
    {
        for (int i = 0; i < ROWS; i++)
        {
            printf("%d\t", transpose[j][i]);
        }
        printf("\n");
    }

    return 0;
}
