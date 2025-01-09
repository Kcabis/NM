#include <stdio.h>
#define MAX 10
#define ORDER 4

// Helper function to calculate factorial
int factorial(int num) {
    int fact = 1, i;
    for (i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n, i, j;
    float x[MAX], y[MAX], xp, h, p, yp;
    float diff[MAX][ORDER] = {0};

    // Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input the values of x and y
    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    // Input the value of x for which y is to be calculated
    printf("Enter the value of x for which the value of y is wanted: ");
    scanf("%f", &xp);

    // Calculate the backward difference table
    for (i = 0; i < n; i++) {
        diff[i][0] = y[i];
    }
    for (j = 1; j < ORDER; j++) {
        for (i = n - 1; i >= j; i--) {
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }

    // Calculate h and p
    h = x[1] - x[0];
    p = (xp - x[n - 1]) / h;

    // Apply Newton's Backward Interpolation formula
    yp = y[n - 1];
    for (i = 1; i < ORDER; i++) {
        float term = p;
        for (j = 1; j < i; j++) {
            term *= (p + j);
        }
        term /= factorial(i);  // Factorial function calculates i!
        term *= diff[n - 1][i];
        yp += term;
    }

    // Output the result
    printf("The interpolated value of y at x = %.3f is %.3f\n", xp, yp);
    return 0;
}
