#include<iostream>
using namespace std;
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
	cout << "\nMatrix 1 : \n";
	printMatrix(mat1, size);
	cout << "\nMatrix 2 : \n";
	printMatrix(mat2, size);
	cout << "\nResult   : \n";
	mat1 = deallocateMemory(mat1, size);
	mat2 = deallocateMemory(mat2, size);
	return 0;
}