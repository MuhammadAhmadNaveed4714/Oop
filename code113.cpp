#include<iostream>
using namespace std;
// Function to replace in an array
void replaceInArray(int arr[], int size, int oldValue, int newValue)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == oldValue)
		{
			arr[i] = newValue;
		}
	}
}
// Function to replace at specific position
void replaceAtPosition(int arr[], int size, int position, int newValue)
{
	if (position < 0 || position >= size)
	{
		cout << "\nInvalid position.\n";
		return;
	}
	arr[position] = newValue;
}
// Function to print an array
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
int main()
{
	const int size = 5;
	int arr[size] = { 1,2,3,4,5 };
	cout << "\nOriginal Array : ";
	printArray(arr, size);
	// replace all occurrences of a value
	int oldValue = 3;
	int newValue = 10;
	replaceInArray(arr, size, oldValue, newValue);
	cout << "\nArray after replacing " << oldValue << " with " << newValue << " : ";
	printArray(arr, size);
	// Repalce at a specific position
	int position = 2;
	newValue = 20;
	replaceAtPosition(arr, size, position, newValue);
	cout << "\nArray after replacing at position " << position << " with " << newValue << " : ";
	printArray(arr, size);
	return 0;
}