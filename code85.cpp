#include<iostream>
using namespace std;
//Function of binary search
void Sorting(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
//Function of entry of elements in array
void entry(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nElement [" << i + 1 << "] = ";
		cin >> arr[i];
	}
} 
//Function to print an array
void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nElement [" << i + 1 << "] = "<< arr[i];
	}
	cout << "\n\n";
}
int main()
{
	int size = 0;
	cout << "\nEnter size of an array : ";
	cin >> size;
	cout << "\nEnter elements of an array : \n";
	int* arr = new int[size];
	entry(arr, size);
	Sorting(arr, size);
	print(arr, size);
	delete[]arr;
	arr = nullptr;
	return 0;
}