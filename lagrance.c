#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x[100], y[100], xp, yp = 0, p;
    int i, j, n;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter data points (x and y):\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    printf("Enter interpolation point: ");
    scanf("%f", &xp);

    for (i = 0; i < n; i++)
    {
        p = 1;
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                p *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += p * y[i];
    }

    printf("Interpolated value at %.3f is %.3f\n", xp, yp);
    return 0;
}

