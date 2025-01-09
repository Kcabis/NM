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
    printf("Enter number of sub-intervals (must be even): ");
    scanf("%d", &sub_interval);

    // Validate the number of sub-intervals
    if (sub_interval % 2 != 0) {
        printf("Error: Number of sub-intervals must be even.\n");
        return 1;
    }

    // Calculate step size
    step_size = (upper - lower) / sub_interval;

    // Apply Simpson's 1/3 Rule
    integration = FUNC(lower) + FUNC(upper);

    for (i = 1; i < sub_interval; i++) {
        float x = lower + i * step_size;
        if (i % 2 == 0) {
            integration += 2 * FUNC(x); // Even terms
        } else {
            integration += 4 * FUNC(x); // Odd terms
        }
    }

    integration *= step_size / 3;

    // Output the result
    printf("Required value of integration is: %.3f\n", integration);

    return 0;
}

