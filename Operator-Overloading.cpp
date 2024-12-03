#include <iostream>
using namespace std;
class Matrix 
{
private:
    int rows;
    int columns;
    int** matrix;
    static int numberOfMatrices; // static counter to track number of matrix objects
    void allocateMemory()
    {
        matrix = new int* [rows];
        for (int i = 0; i < rows; ++i)
        {
            matrix[i] = new int[columns];
        }
    }
    void deallocateMemory()
    {
        for (int i = 0; i < rows; ++i) 
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
public:
    Matrix(int r = 2, int c = 2) : rows(r), columns(c) 
    {
        allocateMemory();
        ++numberOfMatrices;
    }
    Matrix(const Matrix& M) : rows(M.rows), columns(M.columns) 
    {
        allocateMemory();
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j) 
            {
                matrix[i][j] = M.matrix[i][j];
            }
        }
        ++numberOfMatrices;
    }
    ~Matrix()
    {
        deallocateMemory();
        --numberOfMatrices;
    }
    Matrix& operator=(const Matrix& M)
    {
        if (this != &M) 
        {
            deallocateMemory();
            rows = M.rows;
            columns = M.columns;
            allocateMemory();
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < columns; ++j) 
                {
                    matrix[i][j] = M.matrix[i][j];
                }
            }
        }
        return *this;
    }
    Matrix operator+(const Matrix& M)
    {
        if (rows != M.rows || columns != M.columns) 
        {
            cout<<"\nMatrix dimensions must match for addition.";
        }
        Matrix result(rows, columns);
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < columns; ++j) 
            {
                result.matrix[i][j] = matrix[i][j] + M.matrix[i][j];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix& M)
    {
        if (rows != M.rows || columns != M.columns)
        {
            throw invalid_argument("Matrix dimensions must match for subtraction.");
        }
        Matrix result(rows, columns);
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < columns; ++j)
            {
                result.matrix[i][j] = matrix[i][j] - M.matrix[i][j];
            }
        }
        return result;
    }
    Matrix operator*(const Matrix& M)
    {
        if (columns != M.rows)
        {
            cout<<"\nMatrix multiplication requires the number of columns of the first matrix to equal the number of rows of the second matrix.";
        }
        Matrix result(rows, M.columns);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < M.columns; ++j)
            {
                result.matrix[i][j] = 0;
                for (int k = 0; k < columns; ++k)
                {
                    result.matrix[i][j] += matrix[i][k] * M.matrix[k][j];
                }
            }
        }
        return result;
    }
    Matrix operator/(const int N)
    {
        if (N == 0)
        {
            cout<<"\nCannot divide by zero.";
        }
        Matrix result(rows, columns);
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < columns; ++j) 
            {
                result.matrix[i][j] = matrix[i][j] / N;
            }
        }
        return result;
    }
    Matrix& operator+=(const Matrix& M) 
    {
        if (rows != M.rows || columns != M.columns)
        {
            cout<<"\nMatrix dimensions must match for addition.";
        }
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < columns; ++j)
            {
                matrix[i][j] += M.matrix[i][j];
            }
        }
        return *this;
    }
    Matrix& operator-=(const Matrix& M) 
    {
        if (rows != M.rows || columns != M.columns) 
        {
            cout << "\nMatrix dimensions must match for addition."; 
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                matrix[i][j] -= M.matrix[i][j];
            }
        }
        return *this;
    }
    Matrix& operator*=(const Matrix& M) 
    {
        if (columns != M.rows) 
        {
         cout<<("\nMatrix multiplication requires the number of columns of the first matrix to equal the number of rows of the second matrix.");
        }
        Matrix result(rows, M.columns);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < M.columns; ++j)
            {
                result.matrix[i][j] = 0;
                for (int k = 0; k < columns; ++k)
                {
                    result.matrix[i][j] += matrix[i][k] * M.matrix[k][j];
                }
            }
        }
        *this = result;
        return *this;
    }
    Matrix& operator/=(const int N) 
    {
        if (N == 0)
        {
            cout<<("\nCannot divide by zero.");
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                matrix[i][j] /= N;
            }
        }
        return *this;
    }
    bool operator==(const Matrix& M) const
    {
        if (rows != M.rows || columns != M.columns)
            return false;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (matrix[i][j] != M.matrix[i][j]) return false;
            }
        }
        return true;
    }
    bool operator!=(const Matrix& M) const 
    {
        return !(*this == M);
    }
    friend ostream& operator<<(ostream& os, const Matrix& M)
    {
        for (int i = 0; i < M.rows; ++i) 
        {
            for (int j = 0; j < M.columns; ++j) 
            {
                os << M.matrix[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
    friend istream& operator>>(istream& is, Matrix& M)
    {
        for (int i = 0; i < M.rows; ++i)
        {
            for (int j = 0; j < M.columns; ++j)
            {
                is >> M.matrix[i][j];
            }
        }
        return is;
    }
    static int getNumberOfMatrices()
    {
        return numberOfMatrices;
    }
};
int Matrix::numberOfMatrices = 0;
int main() 
{
    int rows, cols;
    // Ask the user for matrix dimensions
    cout << "Enter matrix dimensions (rows and columns): ";
    cin >> rows >> cols;
    // Create two matrices with the given dimensions
    Matrix M1(rows, cols);
    cout << "Enter matrix elements for M1: " << endl;
    cin >> M1;
    Matrix M2(rows, cols);
    cout << "Enter matrix elements for M2: " << endl;
    cin >> M2;
    // Display available operations
    int choice;
    cout << "\nSelect an operation to perform:\n";
    cout << "1. Assignment (=)\n";
    cout << "2. Addition (+)\n";
    cout << "3. Subtraction (-)\n";
    cout << "4. Multiplication (*)\n";
    cout << "5. Division (/)\n";
    cout << "6. In-place Addition (+=)\n";
    cout << "7. In-place Subtraction (-=)\n";
    cout << "8. In-place Multiplication (*=)\n";
    cout << "9. In-place Division (/=)\n";
    cout << "10. Equality (==)\n";
    cout << "11. Inequality (!=)\n";
    cout << "12. Stream Output (<<)\n";
    cout << "13. Stream Input (>>)\n";
    cout << "Enter your choice (1-13): ";
    cin >> choice;
    Matrix result(rows, cols); // To store the result of operations
        switch (choice)
        {
        case 1:
        { // Assignment (=)
            result = M1;
            cout << "M1 assigned to result\n. Result = \n" << endl;
            cout << result;
            break;
        }
        case 2:
        { // Addition (+)
            result = M1 + M2;
            cout << "M1 + M2 = " << endl;
            cout << result;
            break;
        }
        case 3:
        { // Subtraction (-)
            result = M1 - M2;
            cout << "M1 - M2 = " << endl;
            cout << result;
            break;
        }
        case 4: 
        { // Multiplication (*)
            result = M1 * M2;
            cout << "M1 * M2 = " << endl;
            cout << result;
            break;
        }
        case 5: 
        { // Division (/)
            int divisor;
            cout << "Enter a divisor for M1 (non-zero integer): ";
            cin >> divisor;
            result = M1 / divisor;
            cout << "M1 / " << divisor << " = " << endl;
            cout << result;
            break;
        }
        case 6: 
        { // In-place Addition (+=)
            M1 += M2;
            cout << "M1 += M2 results in M1 = " << endl;
            cout << M1;
            break;
        }
        case 7:
        { // In-place Subtraction (-=)
            M1 -= M2;
            cout << "M1 -= M2 results in M1 = " << endl;
            cout << M1;
            break;
        }
        case 8: 
        { // In-place Multiplication (*=)
            M1 *= M2;
            cout << "M1 *= M2 results in M1 = " << endl;
            cout << M1;
            break;
        }
        case 9:
        { // In-place Division (/=)
            int divisor;
            cout << "Enter a divisor for M1 (non-zero integer): ";
            cin >> divisor;
            M1 /= divisor;
            cout << "M1 /= " << divisor << " results in M1 = " << endl;
            cout << M1;
            break;
        }
        case 10:
        { // Equality (==)
            if (M1 == M2) 
            {
                cout << "M1 is equal to M2" << endl;
            }
            else
            {
                cout << "M1 is not equal to M2" << endl;
            }
            break;
        }
        case 11:
        { // Inequality (!=)
            if (M1 != M2) 
            {
                cout << "M1 is not equal to M2" << endl;
            }
            else 
            {
                cout << "M1 is equal to M2" << endl;
            }
            break;
        }
        case 12:
        { // Stream Output (<<)
            cout << "M1 (using stream output operator) = " << endl;
            cout << M1;
            break;
        }
        case 13: 
        { // Stream Input (>>)
            cout << "Enter new elements for M1: " << endl;
            cin >> M1;
            cout << "Updated M1 = " << endl;
            cout << M1;
            break;
        }
        default:
            cout << "Invalid choice! Please choose a valid operation (1-13)." << endl;
            break;
        }
    // Display the number of matrices created
    cout << "Number of Matrix objects created: " << Matrix::getNumberOfMatrices() << endl;
    return 0;
}

