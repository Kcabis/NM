#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cubicSplineInterpolation(int n, double x[], double y[], double xx, double *result) {
    double h[n - 1], a[n], l[n], u[n], z[n];
    double c[n], b[n], d[n];
    int i, j;

    // Step 1: Calculate h[i]
    for (i = 0; i < n - 1; i++) {
        h[i] = x[i + 1] - x[i];
    }

    // Step 2: Calculate alpha
    double alpha[n - 1];
    for (i = 1; i < n - 1; i++) {
        alpha[i] = (3 / h[i] * (y[i + 1] - y[i])) - (3 / h[i - 1] * (y[i] - y[i - 1]));
    }

    // Step 3: Set up the tridiagonal system
    l[0] = 1;
    u[0] = 0;
    z[0] = 0;

    for (i = 1; i < n - 1; i++) {
        l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * u[i - 1];
        u[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    l[n - 1] = 1;
    z[n - 1] = 0;
    c[n - 1] = 0;

    // Step 4: Solve for c, b, and d
    for (j = n - 2; j >= 0; j--) {
        c[j] = z[j] - u[j] * c[j + 1];
        b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3;
        d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
        a[j] = y[j];
    }

    // Step 5: Find the interval containing xx
    for (i = 0; i < n - 1; i++) {
        if (xx >= x[i] && xx <= x[i + 1]) {
            break;
        }
    }

    // Step 6: Calculate the result
    *result = a[i] + b[i] * (xx - x[i]) + c[i] * pow((xx - x[i]), 2) + d[i] * pow((xx - x[i]), 3);
}

int main() {
    int n, i;
    double xx, result;

    // Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];

    // Input x and y values
    printf("Enter the x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i);
        scanf("%lf", &y[i]);
    }

    // Input the x-value for interpolation
    printf("Enter the value of x for interpolation: ");
    scanf("%lf", &xx);

    // Perform cubic spline interpolation
    cubicSplineInterpolation(n, x, y, xx, &result);

    // Output the result
    printf("Interpolated value at x = %.3lf is y = %.3lf\n", xx, result);

    return 0;
}

