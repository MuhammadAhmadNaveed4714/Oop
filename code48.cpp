#include<iostream>
using namespace std;
//Function to dynamically allocate memory for a 1D Array and partition it
void partitionArray(int* originalArray, int leftSize, int rightSize, int totalSize)
{
	//Check if total size matches the sum of left and right partition sizes
	if (leftSize + rightSize != totalSize)
	{
		cout << "\nInvalid partition sizes!\n";
		return;
	}
	//Print the original array
	cout << "\nOriginal Array : ";
	for (int i = 0; i < totalSize; i++)
	{
		cout << originalArray[i] << " ";
	}
	//Partition the array using pointer arithmetic
	int* leftPartition = originalArray;//Points to the start of the right partition
	int* rightPartition = originalArray + leftSize;//Points to the start of the right partition
	//Print the left partition
	cout << "\n\nLeft Partition : ";
	for (int i = 0; i < leftSize; i++)
	{
		cout << leftPartition[i] << " ";
	}
	cout << "\n";
	// Print the right partition
	cout << "\nRight partition: ";
	for (int i = 0; i < rightSize; i++) {
		cout << rightPartition[i] << " ";
	}
	cout << "\n";
}
int main()
{
	int totalSize = 5;
	int* originalArray = new int[totalSize];
	cout << "\nEnter the elements of Original Array : \n";
	for (int i = 0; i < totalSize; i++)
	{
		cin>> originalArray[i];
	}
	int leftSize = 2;
	int rightSize = 3;
	partitionArray(originalArray, leftSize, rightSize, totalSize);
	delete[] originalArray;
	originalArray = nullptr;
	return 0;
}
