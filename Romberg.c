#include <stdio.h>
#include <math.h>

#define FUNC(x) (1 / (1 + (x) * (x))) // Example function: f(x) = 1 / (1 + x^2)

float romberg_integration(float a, float b, float tolerance) {
    float T[10][10] = {0}; // Array to store intermediate results
    int k, j, i;
    float h, sum;

    // Compute T(1,1)
    h = b - a;
    T[1][1] = (h / 2.0f) * (FUNC(a) + FUNC(b));

    for (k = 2; k < 10; k++) {
        // Compute T(k,1) using trapezoidal rule
        h /= 2.0f;
        sum = 0.0f;
        for (i = 1; i <= pow(2, k-2); i++) {
            sum += FUNC(a + (2 * i - 1) * h);
        }
        T[k][1] = 0.5f * T[k-1][1] + h * sum;

        // Compute T(k,j) for j = 2, 3, ..., k
        for (j = 2; j <= k; j++) {
            T[k][j] = (pow(4, j-1) * T[k][j-1] - T[k-1][j-1]) / (pow(4, j-1) - 1);
        }

        // Check for convergence
        if (fabsf(T[k][k] - T[k-1][k-1]) < tolerance) {
            return T[k][k];
        }
    }

    // Return the last computed value if convergence not achieved
    return T[9][9];
}

int main() {
    float a, b, tolerance, result;

    // Input the limits and tolerance
    printf("Enter the lower limit (a): ");
    scanf("%f", &a);
    printf("Enter the upper limit (b): ");
    scanf("%f", &b);
    printf("Enter the tolerance: ");
    scanf("%f", &tolerance);

    // Perform Romberg integration
    result = romberg_integration(a, b, tolerance);

    // Output the result
    printf("The result of the integration is: %.6f\n", result);

    return 0;
}

