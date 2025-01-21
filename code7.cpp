#include <iostream>
using namespace std;
int** allocateMatrix(int row, int col)
{
    int** matrix = new int* [row];
    for (int i = 0; i < row; i++) 
    {
        matrix[i] = new int[col];
    }
    return matrix;
}
void deallocateMatrix(int** matrix, int row) 
{
    for (int i = 0; i < row; i++) 
    {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
}
void multiplyMatrices(int** matrix1, int** matrix2, int** result, int row1, int col1, int row2, int col2) 
{
    if (col1 != row2) 
    {
        cout << "Matrices cannot be multiplied";
        return;
    }
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++) 
        {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) 
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
void printMatrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main() 
{
    int row1=0, col1=0, row2=0, col2=0;
    cout << "Enter the number of rows in Matrix 1: ";
    cin >> row1;
    cout << "Enter the number of columns in Matrix 1: ";
    cin >> col1;
    cout << "Enter the number of rows in Matrix 2: ";
    cin >> row2;
    cout << "Enter the number of columns in Matrix 2: ";
    cin >> col2;
    int** matrix1 = allocateMatrix(row1, col1);
    int** matrix2 = allocateMatrix(row2, col2);
    int** result = allocateMatrix(row1, col2);
    cout << "Enter the elements of Matrix 1:" << endl;
    for (int i = 0; i < row1; i++) 
    {
        for (int j = 0; j < col1; j++) 
        {
            cin >> matrix1[i][j];
        }
    }
    cout << "Enter the elements of Matrix 2:" << endl;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++) 
        {
            cin >> matrix2[i][j];
        }
    }
    multiplyMatrices(matrix1, matrix2, result, row1, col1, row2, col2);
    cout << "Matrix 1:" << endl;
    printMatrix(matrix1, row1, col1);
    cout << "Matrix 2:" << endl;
    printMatrix(matrix2, row2, col2);
    cout << "Resultant Matrix:" << endl;
    printMatrix(result, row1, col2);
    deallocateMatrix(matrix1, row1);
    deallocateMatrix(matrix2, row2);
    deallocateMatrix(result, row1);
    return 0;
}
