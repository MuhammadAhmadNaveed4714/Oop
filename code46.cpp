#include<iostream>
using namespace std;
//Function to dynamicalyy allocate array fora sparse matrix
int** allocateSparseMatrix(int rows, int cols)
{
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	return matrix;
}
//Function to deallocate memory for a sparse matrix
void deallocateSparseMatrix(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
		matrix[i] = nullptr;
	}
	delete[]matrix;
	matrix = nullptr;
}
//Function to convert a sparse matrix to a 1D-Array
int* convertSparseMatrixTo1DArray(int** matrix, int rows, int cols, int& nonZeroCount)
{
	nonZeroCount = 0;
	//count non-zero elements
	for  (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] != 0)
			{
				nonZeroCount++;
			}
		}
	}
	int* array = new int[nonZeroCount];
	int index = 0;
	//Copy non-zero elements to the array
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] != 0)
			{
				array[index++] = matrix[i][j];
			}
		}
	}
	return array;
}
//Function to print a sparse matrix
void printSparseMatrix(int** matrix,int rows,int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j]<<" ";
		}
		cout << "\n";
    }
}
//Function to print a 1D Array
void print1DArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}
int main()
{
	int size = 0;
	cout << "\nEnter size of a matrix : ";
	cin >> size;
	//Dynamically allocate memory for a sparse matrix
	int** sparseMatrix = allocateSparseMatrix(size, size);
	//Initialization of a sparse matrix
	cout << "\nEnter elements of a sparse matrix : \n";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> sparseMatrix[i][j];
		}
	}
	cout << "\nSparse Matrix : \n";
	printSparseMatrix(sparseMatrix, size, size);
	int nonZeroCount = 0;
	int* array = convertSparseMatrixTo1DArray(sparseMatrix, size, size, nonZeroCount);
	cout << "\n1D-Array : \n";
	print1DArray(array, nonZeroCount);
	//Deallocate Memory
	deallocateSparseMatrix(sparseMatrix, size);
	delete[]array;
	array = nullptr;
	return 0;
}