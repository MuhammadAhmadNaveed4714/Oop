#include<iostream>
using namespace std;
//Define a struct to represent a matrix
struct myMatrix
{
	int rows;
	int cols;
	int** mat;
};
//Function to dynamically allocate memory for a matrix
myMatrix createMatrix(int rows, int cols)
{
	myMatrix matrix;
	matrix.rows = rows;
	matrix.cols = cols;
	matrix.mat = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix.mat[i] = new int[cols];
	}
	return matrix;
}
//Function to deallocate memory for a matrix
int** deleteMatrix(myMatrix& matrix)
{
	for (int i = 0; i < matrix.rows; i++)
	{
		delete[]matrix.mat[i];
		matrix.mat[i] = nullptr;
	}
	delete[]matrix.mat;
	matrix.mat = nullptr;
	return matrix.mat;
}
//Function to multiply two matrices
myMatrix multiplyMatrices(myMatrix A, myMatrix B)
{
	if (A.cols != B.rows)
	{
		cout << "\nMatrix multiplication is not possible.\n";
		exit(1);
	}
	myMatrix result = createMatrix(A.rows, B.cols);
	for (int i = 0; i < A.rows; i++)
	{
		for (int j = 0; j < B.cols; j++)
		{
			result.mat[i][j] = 0;
			for (int k = 0; k < A.cols; k++)
			{
				result.mat[i][j] += A.mat[i][k] * B.mat[k][j];
			}
		}
	}
	return result;
}
//Function to display a matrix
void displayMatrix(myMatrix matrix)
{
	for (int i = 0; i < matrix.rows; i++)
	{
		for (int j = 0; j < matrix.cols; j++)
		{
			cout << matrix.mat[i][j] << " ";
		}
		cout << "\n";
	}
}
int main()
{
	int m = 0, n = 0, p = 0;
	//Get dimensions of the matrices
	cout << "\nEnter the number of rows    for matrix A (m) : ";
	cin >> m;
	cout << "\nEnter the number of columns for matrix A (n) : ";
	cin >> n;
	cout << "\nEnter the number of columns for matrix B (p) : ";
	cin >> p;
	//create matrices A and B
	myMatrix A = createMatrix(m, n);
	myMatrix B = createMatrix(n, p);
	//Initialize matrices A and B
	cout << "\nEnter elements for matrix A : \n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A.mat[i][j];
		}
	}
	cout << "\nEnter elements for matrix B : \n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> B.mat[i][j];
		}
	}
	//Multiply matrices A and B
	myMatrix result = multiplyMatrices(A, B);
	//Display the resultant matrix
	cout << "\nMatrix A :\n";
	displayMatrix(A);
	cout << "\nMatrix B :\n";
	displayMatrix(B);
	cout << "\nResultant Matrix :\n";
	displayMatrix(result);
	//Deallocate memory
	deleteMatrix(A);
	deleteMatrix(B);
	deleteMatrix(result);
	return 0;
}