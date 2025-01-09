#include <stdio.h>
#include <math.h>
#define MAX 20
#define TOLERANCE 0.0001

int main() {
    int m, n, i, j, iteration = 0;
    double grid[MAX][MAX], newGrid[MAX][MAX], maxDiff;

    // Input grid dimensions
    printf("Enter the grid dimensions (rows and columns): ");
    scanf("%d %d", &m, &n);

    // Input boundary conditions
    printf("Enter boundary conditions:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                printf("Boundary value at (%d, %d): ", i, j);
                scanf("%lf", &grid[i][j]);
            } else {
                grid[i][j] = 0; // Initial guess for interior points
            }
            newGrid[i][j] = grid[i][j];
        }
    }

    // Iterate until convergence
    do {
        maxDiff = 0.0;
        for (i = 1; i < m-1; i++) {
            for (j = 1; j < n-1; j++) {
                newGrid[i][j] = (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1]) / 4.0;
                if (fabs(newGrid[i][j] - grid[i][j]) > maxDiff) {
                    maxDiff = fabs(newGrid[i][j] - grid[i][j]);
                }
            }
        }

        // Update the grid
        for (i = 1; i < m-1; i++) {
            for (j = 1; j < n-1; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }
        iteration++;
    } while (maxDiff > TOLERANCE);

    // Print the solution
    printf("\nSolution after %d iterations:\n", iteration);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%7.2lf ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}

