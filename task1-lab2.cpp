//#include<iostream>
//using namespace std;
//void multiplyMatrices(int** A, int** B, int** C, int m, int n, int p)
//{
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < p; j++)
//		{
//			C[i][j] = 0;
//			for (int k = 0; k < n; k++)
//			{
//				C[i][j] += A[i][k] * B[k][j];
//			}
//		}
//	}
//}
//void displayMatrix(int** matrix, int rows, int cols)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			cout << matrix[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}
//int main()
//{
//	int m = 0, n = 0, p = 0;
//	cout << "\nEnter number of rows in matrix A : ";
//	cin >> m;
//	cout << "\nEnter number of columns in matrix A : ";
//	cin >> n;
//	cout << "\nEnter number of columns in matyrix B : ";
//	cin >> p;
//	int** A = new int* [m];
//	for (int i = 0; i < m; i++)
//	{
//		A[i] = new int[n];
//	}
//	int** B = new int* [n];
//	for (int i = 0; i < n; i++)
//	{
//		B[i] = new int[p];
//	}
//	int** C = new int* [m];
//	for (int i = 0; i < m; i++)
//	{
//		C[i] = new int[p];
//	}
//	cout << "Enter the elements of matrix A :" << endl;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
//			cin >> A[i][j];
//		}
//	}
//	cout << "Enter the elements of matrix B:" << endl;
//	for (int i = 0; i < n; i++) 
//	{
//		for (int j = 0; j < p; j++) 
//		{
//			cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
//			cin >> B[i][j];
//		}
//	}
//	multiplyMatrices(A, B, C, m, n, p);
//	cout << "Matrix A:" << endl;
//	displayMatrix(A, m, n);
//	cout << "Matrix B:" << endl;
//	displayMatrix(B, n, p);
//	cout << "Resultant Matrix C:" << endl;
//	displayMatrix(C, m, p);
//	for (int i = 0; i < m; i++)
//	{
//		delete[] A[i];
//		A[i] = nullptr;
//	}
//	delete[] A;
//	A = nullptr;
//	for (int i = 0; i < n; i++) 
//	{
//		delete[] B[i];
//		B[i] = nullptr;
//	}
//	delete[] B;
//	B = nullptr;
//	for (int i = 0; i < m; i++) 
//	{
//		delete[] C[i];
//		C[i] = nullptr;
//	}
//	delete[] C;
//	C = nullptr;
//
//	return 0;
//}