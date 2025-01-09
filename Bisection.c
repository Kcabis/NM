#include <stdio.h>
#include <math.h>

// Define the function for which we want to find the root
double function(double x) {
    // Example: f(x) = x^3 - x - 2
    return x * x * x - x - 2;
}

// Bisection method function
void bisection(double a, double b, double tolerance, int max_iterations) {
    double c;

    if (function(a) * function(b) >= 0) {
        printf("Invalid interval: f(a) and f(b) should have opposite signs.\n");
        return;
    }
    int i;
    for (i = 1; i <= max_iterations; i++) {
    	 // Calculate the midpoint
        c = (a + b) / 2;

        // Check if the midpoint is a root or if we have reached the desired tolerance
        if (function(c) == 0.0 || fabs(b - a) / 2 < tolerance) {
            printf("The root is: %lf\n", c);
            return;
        }

        // Decide the side to repeat the steps
        if (function(c) * function(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        printf("Iteration %d: a = %lf, b = %lf, c = %lf, f(c) = %lf\n", i, a, b, c, function(c));
    // Your loop code here
}


    

    printf("The method did not converge within the maximum number of iterations.\n");
}

int main() {
    double a, b, tolerance;
    int max_iterations;

    // Input the interval [a, b], tolerance, and maximum number of iterations
    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    // Call the bisection method
    bisection(a, b, tolerance, max_iterations);

    return 0;
}

