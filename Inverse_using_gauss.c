#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    float a[SIZE][2 * SIZE], ratio;
    int i, j, k, n;
    /* Inputs */
    /* 1. Reading order of the matrix */
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    /* 2. Reading Matrix */
    printf("Enter the elements of the matrix row-wise:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    /* Augmenting Identity Matrix */
    for (i = 1; i <= n; i++)
    {
        for (j = n + 1; j <= 2 * n; j++)
        {
            if (j == (i + n))
                a[i][j] = 1.0;
            else
                a[i][j] = 0.0;
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
        for (j = 1; j <= 2 * n; j++)
        {
            a[i][j] = a[i][j] / a[i][i];
        }

        /* Making all other elements in the current column 0 */
        for (k = 1; k <= n; k++)
        {
            if (k != i)
            {
                ratio = a[k][i];
                for (j = 1; j <= 2 * n; j++)
                {
                    a[k][j] = a[k][j] - ratio * a[i][j];
                }
            }
        }
    }

    /* Displaying Inverse Matrix */
    printf("\nThe Inverse Matrix is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = n + 1; j <= 2 * n; j++)
        {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    },

    getch();
    return 0;
}

