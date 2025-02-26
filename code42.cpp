#include<iostream>
using namespace std;
//Function for binary search
int binarySearch(int array[], int n, int key)
{
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (array[mid] == key)
		{
			return mid;//return the index of the key
		}
		else if (array[mid] < key)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;//return -1 if key is not found
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
	int array[] = { 2,5,8,12,16,23,38,56,72,91 };
	int n = sizeof(array) / sizeof(array[0]);
	cout << "\nOriginal Array : \n";
	printArray(array, n);
	int key = 0;
	cout << "\nEnter the key to search : ";
	cin >> key;
	//Binary Search
	int result = binarySearch(array, n, key);
	if (result != -1)
	{
		cout << "\nKey found at index " << result << " using Binary Search.\n";
	}
	else
	{
		cout << "\nKey not found using Binary Search.\n ";
	}
	return 0;
}