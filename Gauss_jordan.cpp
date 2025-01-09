#include <stdio.h>,m
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    float a[SIZE][SIZE], ratio;
    int i, j, k, n;
    /* Inputs */
    /* 1. Reading number of unknowns */
    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    /* 2. Reading Augmented Matrix */
    printf("Enter the elements of the augmented matrix row-wise:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    /* Applying Gauss-Jordan Elimination */
    for (i = 1; i <= n; i++)
    {
        if (a[i][i] == 0.0)
        {
            printf("Mathematical Error!");
            exit(0);
        }

        /* Making the diagonal element 1 */
        for (j = 1; j <= n + 1; j++)
        {
            a[i][j] = a[i][j] / a[i][i];
        }

        /* Making all other elements in the current column 0 */
        for (k = 1; k <= n; k++)
        {
            if (k != i)
            {
                ratio = a[k][i];
                for (j = 1; j <= n + 1; j++)
                {
                    a[k][j] = a[k][j] - ratio * a[i][j];
                }
            }
        }
    }

    /* Displaying Solution */
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d] = %.2f\n", i, a[i][n + 1]);
    }

    getch();
    return 0;
}

