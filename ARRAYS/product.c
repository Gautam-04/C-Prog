#include <stdio.h>
#define N 50

int main()
{
    int a[N][N], b[N][N], c[N][N], i, j, k, sum, m, n, p, q;

    printf("Enter Number of Rows and Columns for First Matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter Values of First Matrix: ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter Number of Rows and Columns for Second Matrix: ");
    scanf("%d %d", &p, &q);

    printf("Enter Values of Second Matrix: ");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("First Matrix is:-\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("Second Matrix is:-\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    if (n != p)
    {
        printf("Matrix Cannot Be Multiplied");
    }
    else
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
            {
                sum = 0;
                for (k = 0; k < n; k++)
                {
                    sum = sum + (a[i][k] * b[k][j]);
                }
                c[i][j] = sum;
            }
        }
        printf("The Product Of the Matrix is:-\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
            {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
