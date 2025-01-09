#include <stdio.h>
#include <math.h>

#define MAX 20
#define TOLERANCE 0.0001

void solvePoisson(int n, int m, double grid[MAX][MAX], double source[MAX][MAX], double h) {
    double temp[MAX][MAX];
    double maxDiff;
    int i, j;

    do {
        maxDiff = 0.0;

        // Copy grid to temporary grid
        for (i = 1; i < n - 1; i++) {
            for (j = 1; j < m - 1; j++) {
                temp[i][j] = grid[i][j];
            }
        }

        // Update grid points
        for (i = 1; i < n - 1; i++) {
            for (j = 1; j < m - 1; j++) {
                grid[i][j] = 0.25 * (temp[i-1][j] + temp[i+1][j] + temp[i][j-1] + temp[i][j+1] 
                                     - h * h * source[i][j]);
                if (fabs(grid[i][j] - temp[i][j]) > maxDiff) {
                    maxDiff = fabs(grid[i][j] - temp[i][j]);
                }
            }
        }
    } while (maxDiff > TOLERANCE);
}

int main() {
    int n, m, i, j;
    double grid[MAX][MAX] = {0}, source[MAX][MAX] = {0};
    double h;

    // Input grid size and boundary conditions
    printf("Enter the grid size (rows and columns): ");
    scanf("%d %d", &n, &m);

    printf("Enter the grid spacing (h): ");
    scanf("%lf", &h);

    printf("Enter the boundary conditions:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("Boundary value at (%d, %d): ", i, j);
                scanf("%lf", &grid[i][j]);
            }
        }
    }

    printf("Enter the source term values (f(x, y)):\n");
    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < m - 1; j++) {
            printf("Source term at (%d, %d): ", i, j);
            scanf("%lf", &source[i][j]);
        }
    }

    // Solve Poisson's equation
    solvePoisson(n, m, grid, source, h);

    // Display the solution
    printf("\nFinal grid values:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%.4lf ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}

