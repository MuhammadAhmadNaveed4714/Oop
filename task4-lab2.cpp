//#include<iostream>
//using namespace std;
//struct myMatrix
//{
//	int rows;
//	int cols;
//	int** mat;
//};
//myMatrix* createMatrix(int rows, int cols)
//{
//    myMatrix* matrix = new myMatrix;
//    matrix->rows = rows;
//    matrix->cols = cols;
//    matrix->mat = new int* [rows];
//    for (int i = 0; i < rows; i++)
//    {
//        matrix->mat[i] = new int[cols];
//    }
//    return matrix;
//}
//void deleteMatrix(myMatrix* matrix)
//{
//    for (int i = 0; i < matrix->rows; i++)
//    {
//        delete[] matrix->mat[i];
//        matrix->mat[i] = nullptr;
//    }
//    delete[] matrix->mat;
//    matrix->mat = nullptr;
//    delete matrix;
//    matrix = nullptr;
//}
//myMatrix* multiplyMatrices(myMatrix* A, myMatrix* B) 
//{
//    if (A->cols != B->rows)
//    {
//        cout << "Error: Matrices cannot be multiplied." << endl;
//        return NULL;
//    }
//    myMatrix* C = createMatrix(A->rows, B->cols);
//    for (int i = 0; i < A->rows; i++)
//    {
//        for (int j = 0; j < B->cols; j++)
//        {
//            C->mat[i][j] = 0;
//            for (int k = 0; k < A->cols; k++)
//            {
//                C->mat[i][j] += A->mat[i][k] * B->mat[k][j];
//            }
//        }
//    }
//    return C;
//}
//void displayMatrix(myMatrix* matrix) 
//{
//    for (int i = 0; i < matrix->rows; i++) 
//    {
//        for (int j = 0; j < matrix->cols; j++) 
//        {
//            cout << matrix->mat[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//int main()
//{
//    int m=0, n=0, p=0;
//    cout << "Enter the number of rows in matrix A: ";
//    cin >> m;
//    cout << "Enter the number of columns in matrix A: ";
//    cin >> n;
//    cout << "Enter the number of columns in matrix B: ";
//    cin >> p;
//    myMatrix* A = createMatrix(m, n);
//    myMatrix* B = createMatrix(n, p);
//    cout << "Enter the elements of matrix A:" << endl;
//    for (int i = 0; i < m; i++) 
//    {
//        for (int j = 0; j < n; j++)
//        {
//            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
//            cin >> A->mat[i][j];
//        }
//    }
//    cout << "Enter the elements of matrix B:" << endl;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < p; j++) 
//        {
//            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
//            cin >> B->mat[i][j];
//        }
//    }
//    myMatrix* C = multiplyMatrices(A, B);
//    cout << "Matrix A:" << endl;
//    displayMatrix(A);
//    cout << "Matrix B:" << endl;
//    displayMatrix(B);
//    cout << "Matrix C (A * B):" << endl;
//    displayMatrix(C);
//    deleteMatrix(A);
//    deleteMatrix(B);
//    deleteMatrix(C);
//	return 0;
//}