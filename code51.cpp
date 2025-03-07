#include<iostream>
using namespace std;
//Function to multiply two matrices
void multiplyMatrices(int** mat1, int** mat2, int** result, int size)
{
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
}
//Function to print a matrix
void printMatrix(int** mat, int size)
{
	for(int i=0;i<size;i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << mat[i][j] << " ";
	    }
		cout << "\n";
	}
}
//Function to take input for a matrix
void input(int** mat, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> mat[i][j];
		}
	}
}
int main()
{
	int size = 0;
	cout << "\nEnter size of square matrices : ";
	cin >> size;
	int** mat1 = new int* [size];
	int** mat2 = new int* [size];
	int** result = new int* [size];
	for (int i = 0; i < size; i++)
	{
		mat1[i] = new int[size];
		mat2[i] = new int[size];
		result[i] = new int[size];
	}
	cout << "\nEnter elements of matrix 1 : ";
	input(mat1, size);
	cout << "\nEnter elements of matrix 2 : ";
	input(mat2, size);
	multiplyMatrices(mat1, mat2, result, size);
	cout << "\nMatrix 1 : \n";
	printMatrix(mat1, size);
	cout << "\nMatrix 2 : \n";
	printMatrix(mat2, size);
	cout << "\nResult   : \n";
	printMatrix(result, size);
	for (int i = 0; i < size; i++)
	{
		delete[]mat1[i];
		mat1[i] = nullptr;
		delete[]mat2[i];
		mat2[i] = nullptr;
		delete[]result[i];
		result[i] = nullptr;
	}
	delete[]mat1;
	mat1 = nullptr;
	delete[]mat2;
	mat2 = nullptr;
	delete[]result;
	result = nullptr;
	return 0;
}