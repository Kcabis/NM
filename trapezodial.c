#include <stdio.h>
#include <math.h>

#define FUNC(x) (1 / (1 + pow(x, 2)))

int main() {
    float lower, upper, integration = 0.0, step_size, k;
    int sub_interval, i;

    // Input lower limit of integration
    printf("Enter lower limit of integration: ");
    scanf("%f", &lower);

    // Input upper limit of integration
    printf("Enter upper limit of integration: ");
    scanf("%f", &upper);

    // Input number of sub-intervals
    printf("Enter number of sub-intervals: ");
    scanf("%d", &sub_interval);

    // Calculate step size
    step_size = (upper - lower) / sub_interval;

    // Apply the trapezoidal rule
    for (i = 1; i < sub_interval; i++) {
        k = lower + i * step_size;
        integration += 2 * FUNC(k);
    }
    integration += FUNC(lower) + FUNC(upper);
    integration *= step_size / 2;

    // Print the result
    printf("Required value of integration is: %.3f\n", integration);

    return 0;
}

