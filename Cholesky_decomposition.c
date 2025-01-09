#include <stdio.h>
#include <math.h>

#define MAX 10

void choleskyDecomposition(float A[MAX][MAX], int n, float L[MAX][MAX]) {
    int i, j, k;

    // Initialize L matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            L[i][j] = 0;
        }
    }

    // Perform Cholesky decomposition
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            float sum = 0;

            // Compute the summation term
            for (k = 0; k < j; k++) {
                sum += L[i][k] * L[j][k];
            }

            if (i == j) { // Diagonal elements
                L[i][j] = sqrt(A[i][i] - sum);
            } else { // Off-diagonal elements
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}

int main() {
    float A[MAX][MAX], L[MAX][MAX];
    int n, i, j;

    // Input matrix size
    printf("Enter the size of the matrix (n): ");
    scanf("%d", &n);

    // Input matrix A
    printf("Enter the elements of the matrix A (%dx%d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Perform Cholesky decomposition
    choleskyDecomposition(A, n, L);

    // Display results
    printf("\nLower Triangular Matrix L:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) { // Print only lower triangular part
            printf("%.2f ", L[i][j]);
        }
        printf("\n");
    }

    return 0;
}

