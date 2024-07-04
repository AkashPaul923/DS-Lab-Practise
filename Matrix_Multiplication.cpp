#include <iostream>
using namespace std;

// Function to allocate memory for a matrix
int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// Function to deallocate memory for a matrix
void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Function to input matrix elements
void inputMatrix(int** matrix, int rows, int cols) {
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int** matrix, int rows, int cols) {
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to multiply two matrices
int** multiplyMatrices(int** matrixA, int rowsA, int colsA, int** matrixB, int rowsB, int colsB) {
    if (colsA != rowsB) {
        cout << "Matrix multiplication not possible.\n";
        return nullptr;
    }

    int** result = allocateMatrix(rowsA, colsB);

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return result;
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter the number of rows and columns for matrix A: ";
    cin >> rowsA >> colsA;
    int** matrixA = allocateMatrix(rowsA, colsA);
    inputMatrix(matrixA, rowsA, colsA);

    cout << "Enter the number of rows and columns for matrix B: ";
    cin >> rowsB >> colsB;
    int** matrixB = allocateMatrix(rowsB, colsB);
    inputMatrix(matrixB, rowsB, colsB);

    int** result = multiplyMatrices(matrixA, rowsA, colsA, matrixB, rowsB, colsB);

    if (result != nullptr) {
        displayMatrix(result, rowsA, colsB);
        deallocateMatrix(result, rowsA);
    }

    deallocateMatrix(matrixA, rowsA);
    deallocateMatrix(matrixB, rowsB);

    return 0;
}
