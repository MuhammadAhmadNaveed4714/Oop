//#include<iostream>
//using namespace std;
//int countNonZero(int** matrix, int rows, int cols)
//{
//	int count = 0;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			if (matrix[i][j] != 0)
//			{
//				count++;
//			}
//		}
//	}
//	return count;
//}
//void convertTo1DArray(int** matrix, int rows, int cols, int* arr, int nonZeroCount)
//{
//	int index = 0;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			if (matrix[i][j] != 0)
//			{
//				arr[index] = matrix[i][j];
//				index++;
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
//		cout << endl;
//	}
//}
//void displayArray(int* array, int size)
//{
//	for (int i = 0; i < size; i++) 
//	{
//		cout << array[i] << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	int rows = 0, cols = 0;
//	cout << "\nEnter the number of rows : ";
//	cin >> rows;
//	cout << "\nEnter the number of columns : ";
//	cin >> cols;
//	int** matrix = new int* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		matrix[i] = new int[cols];
//	}
//	cout << "Enter the elements of the sparse matrix:" << endl;
//	for (int i = 0; i < rows; i++) 
//	{
//		for (int j = 0; j < cols; j++) 
//		{
//			cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
//			cin >> matrix[i][j];
//		}
//	}
//	cout << "Sparse Matrix:" << endl;
//	displayMatrix(matrix, rows, cols);
//	int nonZeroCount = countNonZero(matrix, rows, cols);
//	int* array = new int[nonZeroCount];
//	convertTo1DArray(matrix, rows, cols, array, nonZeroCount);
//	cout << "1D Array:" << endl;
//	displayArray(array, nonZeroCount);
//	for (int i = 0; i < rows; i++)
//	{
//		delete[] matrix[i];
//		matrix[i] = nullptr;
//	}
//	delete[] matrix;
//	matrix = nullptr;
//	delete[] array;
//	array = nullptr;
//	return 0;
//}