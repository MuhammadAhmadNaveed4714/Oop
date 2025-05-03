#include<iostream>
using namespace std;
// Function to reverse an array
void reverse(int* a, int s)
{
	int start = 0;
	int end = s - 1;
	int temp = 0;
	while (end > start)
	{
		temp = a[end];
		a[end] = a[start];
		a[start] = temp;
		start++;
		end--;
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
// Function to input an array
void input(int* a, int s)
{
	cout << "\n\t\t\t\t\t\tInputting an array : \n";
	for (int i = 0; i < s; i++)
	{
		cout << "\nEntry no " << i << " : ";
		cin >> a[i];
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
	reverse(arr, size);
	cout << "\n\n\n\t\t\t\t\tAfter implementing reverse function :\n\n\n";
	print(arr, size);
	delete[]arr;
	arr = nullptr;
	return 0;
}