#include <iostream>
#include<string>
using namespace std;
string checkMatrixSymmetry(int** mat, const int size) 
{
    int** transpose = new int* [size];
    for (int i = 0; i < size; i++)
    {
        transpose[i] = new int[size];
    }
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            *(transpose[j] + i) = *(mat[i] + j);
        }
    }
    bool isSymmetric = true;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) 
        {
            if (*(mat[i] + j) != *(transpose[i] + j)) 
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
    bool isSkewSymmetric = true;
    if (!isSymmetric)
    {
        for (int i = 0; i < size; i++) 
        {
            for (int j = 0; j < size; j++) 
            {
                if (*(mat[i] + j) != -*(transpose[i] + j)) 
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
    }
    for (int i = 0; i < size; i++) 
    {
        delete[] transpose[i];
        transpose[i] = nullptr;
    }
    delete[] transpose;
    transpose = nullptr;
    if (isSymmetric) 
    {
        return "symmetric";
    }
    else if (isSkewSymmetric) 
    {
        return "skew symmetric";
    }
    else 
    {
        return "neither symmetric nor skew symmetric";
    }
}
int main() 
{
    int size;
    cout << "Enter the size of the square matrix: ";
    cin >> size;
    int** mat = new int* [size];
    for (int i = 0; i < size; i++) 
    {
        mat[i] = new int[size];
    }
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) 
        {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> *(mat[i] + j);
        }
    }
    string result = checkMatrixSymmetry(mat, size);
    cout << "The matrix is " << result << "." << endl;
    for (int i = 0; i < size; i++)
    {
        delete[] mat[i];
        mat[i] = nullptr;
    }
    delete[] mat;
    mat = nullptr;
    return 0;
}

