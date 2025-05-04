#include<iostream>
using namespace std;
// Function to input numbers
void input(int* a, int s)
{
	cout << "\n\t\t\t\t\t\tEntry of numbers :\n";
	for (int i = 0; i < s; i++)
	{
		cout << "\nEnter input " << i << " : ";
		cin >> a[i];
	}
}
// Function to print an array
void print(int* a, int s)
{
	cout << "\n\t\t\t\t\tPrinting of an array : ";
	for (int i = 0; i < s; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}
// Function of buuble sort
void bubbleSort(int* a, int s)
{
	int temp = 0;
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int size = 0;
	cout << "\nEnter size of an array : ";
	cin >> size;
	int* arr = new int[size];
	input(arr, size);
	print(arr, size);
	bubbleSort(arr, size);
	print(arr, size);
	delete[]arr;
	arr = nullptr;
	return 0;
}