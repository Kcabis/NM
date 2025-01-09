#include <stdio.h>

#define MAX 10

void doolittleDecomposition(float A[MAX][MAX], int n, float L[MAX][MAX], float U[MAX][MAX]) {
    int i, j, k;

    // Initialize L and U matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            L[i][j] = (i == j) ? 1 : 0; // Diagonal elements of L are 1
            U[i][j] = 0;
        }
    }

    // Perform Doolittle decomposition
    for (i = 0; i < n; i++) {
        // Compute U[i][j]
        for (j = i; j < n; j++) {
            U[i][j] = A[i][j];
            for (k = 0; k < i; k++) {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }

        // Compute L[j][i]
        for (j = i + 1; j < n; j++) {
            L[j][i] = A[j][i];
            for (k = 0; k < i; k++) {
                L[j][i] -= L[j][k] * U[k][i];
            }
            L[j][i] /= U[i][i];
        }
    }
}

int main() {
    float A[MAX][MAX], L[MAX][MAX], U[MAX][MAX];
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

    // Perform Doolittle decomposition
    doolittleDecomposition(A, n, L, U);

    // Display results
    printf("\nLower Triangular Matrix L:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f ", L[i][j]);
        }
        printf("\n");
    }

    printf("\nUpper Triangular Matrix U:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f ", U[i][j]);
        }
        printf("\n");
    }

    return 0;
}

