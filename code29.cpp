#include<iostream>
using namespace std;
//Function to multiply two matrices
int** multiplyMatrices(int** mat1, int** mat2, int size)
{
	int** result = new int* [size];
	for (int i = 0; i < size; i++)
	{
		result[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < size; k++)
			{
				result[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	return result;
}
//Function to print a matrix
void printMatrix(int** mat, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
}
//Function to take input for a matrix
int** input(int size)
{
	int** mat = new int* [size];
	for (int i = 0; i < size; i++)
	{
		mat[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> mat[i][j];
		}
	}
	return mat;
}
//Function to deallocate memory
int** deallocateMemory(int** mat, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[]mat[i];
		mat[i] = nullptr;
	}
	delete[]mat;
	mat = nullptr;
	return mat;
}
int main()
{
	int size = 0;
	cout << "\nEnter size of square matrices : ";
	cin >> size;
	cout << "\nEnter elements of matrix 1 : ";
	int** mat1 = input(size);
	cout << "\nEnter elements of matrix 2 : ";
	int** mat2 = input(size);
	int**result=multiplyMatrices(mat1, mat2, size);
	cout << "\nMatrix 1 : \n";
	printMatrix(mat1, size);
	cout << "\nMatrix 2 : \n";
	printMatrix(mat2, size);
	cout << "\nResult   : \n";
	printMatrix(result, size);
	mat1 = deallocateMemory(mat1,size);
	mat2 = deallocateMemory(mat2, size);
	result = deallocateMemory(result, size);
	return 0;
}