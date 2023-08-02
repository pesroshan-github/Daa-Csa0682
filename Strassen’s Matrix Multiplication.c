#include <stdio.h>

// Function to add two matrices
void matrixAddition(int n, int A[][n], int B[][n], int C[][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void matrixSubtraction(int n, int A[][n], int B[][n], int C[][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply two matrices using Strassen's algorithm
void strassenMatrixMultiplication(int n, int A[][n], int B[][n], int C[][n]) {
    // Base case: If the matrix size is 1x1, perform a simple multiplication
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize], P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];

    int i, j;

    // Divide the matrices into four sub-matrices
    for (i = 0; i < newSize; i++) {
        for (j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate the seven products P1, P2, ..., P7
    matrixAddition(newSize, A11, A22, C11);
    matrixAddition(newSize, B11, B22, C12);
    matrixAddition(newSize, A21, A22, C21);
    matrixSubtraction(newSize, B12, B22, C22);
    matrixSubtraction(newSize, B21, B11, P1);
    matrixAddition(newSize, A11, A12, P2);
    matrixAddition(newSize, A21, A22, P3);
    matrixSubtraction(newSize, B22, B12, P4);
    matrixAddition(newSize, A11, A22, P5);
    matrixAddition(newSize, B11, B12, P6);
    matrixSubtraction(newSize, A12, A22, P7);

    // Calculate the four sub-products recursively using Strassen's algorithm
    strassenMatrixMultiplication(newSize, C11, C12, C11);
    strassenMatrixMultiplication(newSize, P1, P2, C12);
    strassenMatrixMultiplication(newSize, P3, P4, C21);
    strassenMatrixMultiplication(newSize, C22, P5, C22);
    strassenMatrixMultiplication(newSize, P6, P7, C21);
    
    // Calculate the result matrices C11, C12, C21, C22
    matrixAddition(newSize, C11, C12, C11);
    matrixAddition(newSize, C21, C22, C22);
    
    // Combine the sub-matrices into the final result matrix C
    for (i = 0; i < newSize; i++) {
        for (j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int n, int matrix[][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4; // Size of the matrices (should be a power of 2 for simplicity)

    int A[][4] = { {1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16} };

    int B[][4] = { {17, 18, 19, 20},
                   {21, 22, 23, 24},
                   {25, 26, 27, 28},
                   {29, 30, 31, 32} };

    int C[n][n];

    printf("Matrix A:\n");
    printMatrix(n, A);

    printf("\nMatrix B:\n");
    printMatrix(n, B);

    strassenMatrixMultiplication(n, A, B, C);

    printf("\nMatrix C (Result of A * B):\n");
    printMatrix(n, C);

    return 0;
}

