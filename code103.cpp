#include<iostream>
using namespace std;
// Function to create a double matrix
int** dmatrix(int r, int c)
{
	int** mat = new int* [r];
	for (int i = 0; i < r; i++)
	{
		mat[i] = new int[c];
	}
	return mat;
}
// Function to print a double matrix
void print(int** m, int r, int c)
{
	cout << "\n";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << "mat [" << i<<"]" << "[" << j << "]" << " = " << m[i][j] << "\t\t\t\t\t";
		}
		cout << "\n";
	}
}
// Function to remove a double matrix
int** remove(int** m, int r)
{
	for (int i = 0; i < r; i++)
	{
		delete[]m[i];
		m[i] = nullptr;
	}
	delete[]m;
	m = nullptr;
	return m;
}
// Function to input a matrix
void input(int** m, int r, int c)
{
	cout << "\n\n\t\t\t\t\tInput operation starts : \n";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << "Enter input for mat [" << i << "]" << "[" << j << "] = ";
			cin >> m[i][j];
		}
	}
}
// Function to get resultant matrix
int** res(int** m1, int** m2, int r1, int c1, int r2, int c2)
{
	if (c1 != r2)
	{
		cout << "\nMultiplication does not exist.\n";
		return nullptr;
	}
	else
	{
		int** res = dmatrix(r1, c2);
		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < c2; j++)
			{
				res[i][j] = 0;
				for (int k = 0; k < r2; k++)
				{
					res[i][j] += (m1[i][k] * m2[k][j]);
				}
			}
		}
		return res;
	}
}
int main()
{
	int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
	cout << "\nEnter rows for matrix 1 : ";
	cin >> r1;
	cout << "\nEnter columns for matrix 1 : ";
	cin >> c1;
	cout << "\nEnter rows for matrix 2 : ";
	cin >> r2;
	cout << "\nEnter columns for matrix 2 : ";
	cin >> c2;
	int** mat1=dmatrix(r1, c1);
	input(mat1, r1, c1);
	print(mat1, r1, c1);
	int** mat2 = dmatrix(r2, c2);
	input(mat2, r2, c2);
	print(mat2, r2, c2);
	int** mat3 = res( mat1,  mat2,  r1,  c1,  r2,  c2);
	if (mat3 == nullptr)
	{
		cout << "\nThere is no multiplication of matrices.\n";
	}
	else
	{
		cout << "\nMultiplication of resultant matrix : \n";
		print(mat3, r1, c2);
	}
	mat1 = remove(mat1, r1);
	mat2 = remove(mat2, r2);
	mat3 = remove(mat3, r1);
	return 0;
}