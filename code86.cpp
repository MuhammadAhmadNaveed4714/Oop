#include<iostream>
using namespace std;
//Function to allocate a 2-d array
int** get2dArray(int r,int c)
{
	int** a = new int* [r];
	for (int i = 0; i < r; i++)
	{
		a[i] = new int[c];
	}
	return a;
}
//Function to get elements in an array
void entry(int** a, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
		}
	}
}
//Function to print a 2-d Array
void print(int** a,int r,int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << a[i][j] <<" ";
		}
		cout << "\n";
	}
}
//Function to get multiplication matrix
int** getMultiplicationMatrix(int** a, int** b, int r1, int c1,  int c2)
{
	int** res = get2dArray(r1, c2);
	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < c1; k++)
			{
				res[i][j] += (a[i][k] * b[k][j]);
			}
		}
	}
	return res;
}
//Function to deallocate a 2-d memory
void deallocateMemory(int** a, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		delete[] a[i];
		a[i] = nullptr;
	}
}
int main()
{
	int r1 = 0, c1 = 0,r2=0,c2=0;
	cout << "\nEnter number of rows of a matrix 1 : ";
	cin >> r1;
	cout << "\nEnter number of columns of a matrix 1 : ";
	cin >> c1;
	cout << "\nEnter number of rows of a matrix : ";
	cin >> r2;
	cout << "\nEnter number of columns of a matrix : ";
	cin >> c2;
	if (c1 != r2)
	{
		cout << "\nMultiplication matrix will not be made.\n";
		return 0;
	}
	int ** mat1=get2dArray(r1, c1);
	cout << "\nEnter the number of elements in a matrix 1 : \n";
	entry(mat1, r1, c1);
	cout << "\nPrinting of elements of matrix 1 : \n\n";
	print(mat1,r1,c1);
	int ** mat2=get2dArray(r2, c2);
	cout << "\nEnter the number of elements in a matrix 2 : \n";
	entry(mat2, r2, c2);
	cout << "\nPrinting of elements of matrix 2 : \n\n";
	print(mat2,r2,c2);
	int** res = getMultiplicationMatrix(mat1, mat2, r1, c1, c2);
	cout << "\nPrinting of elements of resultant matrix  : \n\n";
	print(res,r1,c2);
	deallocateMemory(mat1, r1, c1);
	mat1 = nullptr;
	deallocateMemory(mat2, r2, c2);
	mat2 = nullptr;
	deallocateMemory(res, r1, c2);
	res = nullptr;
	return 0;
}