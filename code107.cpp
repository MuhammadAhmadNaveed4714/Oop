#include<iostream>
using namespace std;
// Function to input an array
void input(int* a, int size)
{
	cout << "\n\t\t\t\t\tInputting an array : ";
	for (int i = 0; i < size; i++)
	{
		cout << "\nEnter number " << i << " : ";
		cin >> a[i];
	}
	cout << "\n";
}
// Function of bubble sorting
void bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
// Function of print
void print(int* a, int s)
{
	cout << "\n\t\t\t\t\tPrinting of an array : ";
	for (int i = 0; i < s; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}
int main()
{
	int s = 0;
	cout << "\nEnter size of an array : ";
	cin >> s;
	int* a = new int[s];
	input(a, s);
	print(a, s);
	bubbleSort(a, s);
	cout << "\n\t\t\t\t\t\tAfter Bubble sort : \n";
	print(a, s);
	delete[]a;
	a = nullptr;
	return 0;
}