#include<iostream>
using namespace std;
//Function to check Matrix Symmetry
string checkMatrixSymmetry(int** mat, const int size)
{
	//check if matrix is symmetry
	bool isSymmetric = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (*(mat[i] + j) != *(mat[j] + i))
			{
				isSymmetric = false;
				break;
			}
		}
		if (!isSymmetric)
		{
			break;
		}
	}
	if (isSymmetric)
	{
		return "symmetric.";
	}
	//Check if matrix is skew symmetric
	bool isSkewSymmetric = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (*(mat[i] + j) != -(*(mat[j] + 1)))
			{
				isSkewSymmetric = false;
				break;
			}
		}
		if (!isSkewSymmetric)
		{
			break;
		}
	}
	if (isSkewSymmetric)
	{
		return "skew symmetric.";
	}
	else
	{
		return "neither symmetric nor skew symmetric.";
	}
}
int main()
{
	int size = 0;
	cout << "\nEnter size of square matrix : ";
	cin >> size;
	//Dynamically allocate 2D array
	int** mat = new int* [size];
	for (int i = 0; i < size; i++)
	{
		mat[i] = new int[size];
	}
	cout << "\nEnter elements of a matrix : ";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> mat[i][j];
		}
	}
	string result = checkMatrixSymmetry(mat, size);
	cout << "\nMatrix is " << result << "\n";
	//Deallocate memory
	for (int i = 0; i < size; i++)
	{
		delete[] mat[i];
		mat[i] = nullptr;
	}
	delete[]mat;
	mat = nullptr;
	return 0;
}