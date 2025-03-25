#include<iostream>
using namespace std;
int sLargest(int* arr, int size)
{
	int largest = INT_MIN + 1;
	int sLargest = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > largest)
		{
			sLargest = largest;
			largest = arr[i];
		}
	}
	return sLargest;
}
void getElements(int* arr, int size)
{
	cout << "\nEnter elements of an array : \n";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}
void printElements(int* arr, int size)
{
	cout << "\n\nDisplay of elements of an array : \n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << "\n";
}
int main()
{
	int size = 0;
	cout << "\nEnter size of the array : ";
	cin >> size;
	int* arr = new int[size];
	getElements(arr, size);
	cout << "\n\nSecond largest element of an array : " << sLargest(arr, size); 
	printElements(arr, size);
	delete[] arr;
	arr = nullptr;
	return 0;
}