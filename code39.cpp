#include<iostream>
using namespace std;
//Function to swap two elements
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//Function to sort an array using bubble-sort
void bubbleSort(int array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
}
//Function to print an array
void printArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}
int main()
{
	int array[] = { 64,34,25,12,22,11,90 };
	int n = sizeof(array) / sizeof(array[0]);
	cout << "\nOriginal Array :\n\n";
	printArray(array, n);
	bubbleSort(array, n);
	cout << "\nSorted Array :\n\n";
	printArray(array, n);
	return 0;
}