#include <stdio.h>
#include <math.h>

// Define the g(x) function for Fixed-Point Iteration
double g(double x) {
    // Example: g(x) = (x^3 - 2)/3
    return (x * x * x - 2) / 3;
}

// Fixed-Point Iteration Method Function
void fixed_point_iteration(double x0, double tolerance, int max_iterations) {
    double x1;
    int i;

    for (i = 1; i <= max_iterations; i++) {
        // Calculate the next approximation
        x1 = g(x0);

        // Print the current iteration, x0, and g(x0)
        printf("Iteration %d: x = %lf, g(x) = %lf\n", i, x0, x1);

        // Check if the result is within the desired tolerance
        if (fabs(x1 - x0) < tolerance) {
            printf("The root is: %lf\n", x1);
            return;
        }

        // Update x0 for the next iteration
        x0 = x1;
    }

    printf("The method did not converge within the maximum number of iterations.\n");
}

int main() {
    double x0, tolerance;
    int max_iterations;

    // Input the initial guess, tolerance, and maximum number of iterations
    printf("Enter the initial guess: ");
    scanf("%lf", &x0);

    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    // Call the Fixed-Point Iteration method
    fixed_point_iteration(x0, tolerance, max_iterations);

    return 0;
}

