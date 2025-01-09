#include <stdio.h>
#include <conio.h>

#define SIZE 50

int main() {
    int n, i;
    float x[SIZE], y[SIZE];
    float sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0;
    float a, b;

    // Input number of data points
    printf("How many data points? ");
    scanf("%d", &n);

    // Input data points
    printf("Enter data points (x and y):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i + 1);
        scanf("%f", &y[i]);
    }

    // Calculate sums
    for (i = 0; i < n; i++) {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
    }

    // Calculate coefficients a and b
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;

    // Display results
    printf("Values are: a = %.2f and b = %.2f\n", a, b);
    printf("Equation of best fit: Y = %.2f + %.2fX\n", a, b);

    return 0;
}

