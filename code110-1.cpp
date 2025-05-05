#include<iostream>
using namespace std;
// Function to concatenate an array
int* concatenate(int* destination, int* source, int destSize, int srcSize)
{
	int* temp = new int[destSize + srcSize];
	for (int i = 0; i < destSize; i++)
	{
		temp[i] = destination[i];
	}
	for (int i = 0; i < srcSize; i++)
	{
		temp[destSize + i] = source[i];
	}
	delete[] destination;
	return temp;
}
// Function to input an array
void input(int* a, int s)
{
	cout << "\nInputting of an array : \n";
	for (int i = 0; i < s; i++)
	{
		cout << "\nEntry no " << i << " : ";
		cin >> a[i];
	}
	cout << "\n";
}
// Function to print an array
void print(int* a, int s)
{
	cout << "\n\t\t\t\t\tPrinting of an array : \n";
	for (int i = 0; i < s; i++)
	{
		cout << "\nArray [" << i << "] = " << a[i];
	}
	cout << "\n";
}
int main()
{
	int destSize = 0;
	int srcSize = 0;
	cout << "\nEnter size of destination array : ";
	cin >> destSize;
	cout << "\nEnter size of source array : ";
	cin >> srcSize;
	int* destination = new int[destSize];
	input(destination, destSize);
	int* source = new int[srcSize];
	input(source, srcSize);
	print(destination, destSize);
	print(source, srcSize);
	destination = concatenate(destination, source, destSize, srcSize);
	cout << "\n\t\t\t\t\tConcatenated Array : \n";
	print(destination, destSize + srcSize);
	delete[]destination;
	destination = nullptr;
	delete[]source;
	source = nullptr;
	return 0;
}