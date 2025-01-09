#include <stdio.h>
#include <math.h>

// Define the function for which we want to find the root
double function(double x) {
    // Example: f(x) = x^3 - x - 2
    return x * x * x - x - 2;
}

// Define the derivative of the function
double derivative(double x) {
    // Derivative: f'(x) = 3x^2 - 1
    return 3 * x * x - 1;
}

// Newton-Raphson method function
void newton_raphson(double x0, double tolerance, int max_iterations) {
    double x1, fx, fdx;
    int i;

    for (i = 1; i <= max_iterations; i++) {
        // Calculate the function value and its derivative at x0
        fx = function(x0);
        fdx = derivative(x0);

        // Check if the derivative is zero to avoid division by zero
        if (fdx == 0.0) {
            printf("Error: Derivative is zero. Method fails.\n");
            return;
        }

        // Calculate the next approximation
        x1 = x0 - fx / fdx;

        // Print the current iteration, x0, and f(x0)
        printf("Iteration %d: x = %lf, f(x) = %lf\n", i, x0, fx);

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

    // Call the Newton-Raphson method
    newton_raphson(x0, tolerance, max_iterations);

    return 0;
}

