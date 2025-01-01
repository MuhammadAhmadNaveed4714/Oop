#include<iostream>
using namespace std;
int* mergeArrays(int* leftArray, int* rightArray, int leftSize, int rightSize)
{
    int* mergedArray = new int[leftSize + rightSize];
    for (int i = 0; i < leftSize; i++)
    {
        mergedArray[i] = leftArray[i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        mergedArray[leftSize + i] = rightArray[i];
    }
    return mergedArray;
}
void printArray(int* array, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main()
{
    int lsize = 0, rsize = 0;
    cout << "\n\nEnter size of an array on left side : ";
    cin >> lsize;
    cout << "\nEnter size of an array on right side : ";
    cin >> rsize;
    int* leftArray = new int[lsize];
    int* rightArray = new int[rsize];
    cout << "\nEnter elements of an array on left side :  \n";
    for (int i = 0; i < lsize; i++)
    {
        cin >> leftArray[i];
    }
    cout << "\nEnter elements of an array on right side :  \n";
    for (int i = 0; i < rsize; i++)
    {
        cin >> rightArray[i];
    }
    cout << "\n\nLeft Array : ";
    printArray(leftArray, lsize);
    cout << "\n\nRight Array : ";
    printArray(rightArray, rsize);
    int* mergedArray = mergeArrays(leftArray, rightArray, lsize, rsize);
    cout << "\n\nMerged array: ";
    printArray(mergedArray, lsize + rsize);
    delete[] leftArray;
    leftArray = nullptr;
    delete[] rightArray;
    rightArray = nullptr;
    delete[] mergedArray;
    mergedArray = nullptr;
	return 0;
}