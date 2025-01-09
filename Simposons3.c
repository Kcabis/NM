#include <stdio.h>
#include <math.h>

#define FUNC(x) (1 / (1 + pow(x, 2)))

int main() {
    float lower, upper, integration = 0.0, step_size;
    int sub_interval, i;

    // Input lower limit
    printf("Enter lower limit of integration: ");
    scanf("%f", &lower);

    // Input upper limit
    printf("Enter upper limit of integration: ");
    scanf("%f", &upper);

    // Input number of sub-intervals
    printf("Enter number of sub-intervals (must be a multiple of 3): ");
    scanf("%d", &sub_interval);

    // Validate the number of sub-intervals
    if (sub_interval % 3 != 0) {
        printf("Error: Number of sub-intervals must be a multiple of 3.\n");
        return 1;
    }

    // Calculate step size
    step_size = (upper - lower) / sub_interval;

    // Apply Simpson's 3/8 Rule
    integration = FUNC(lower) + FUNC(upper);

    for (i = 1; i < sub_interval; i++) {
        float x = lower + i * step_size;

        if (i % 3 == 0) {
            integration += 2 * FUNC(x); // Terms that are multiples of 3
        } else {
            integration += 3 * FUNC(x); // All other terms
        }
    }

    integration *= (3 * step_size / 8);
n
    // Output the result
    printf("Required value of integration is: %.3f\n", integration);

    return 0;
}

