#include<iostream>
using namespace std;
int* resizeArray(int* inArray, const int size)
{
	int* newArray = new int[size * 2];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = inArray[i];
	}
	for (int i = size; i < size * 2; i++)
	{
		newArray[i] = (inArray[i - size] * 2);
	}
	return newArray;
}
int main()
{
	int size = 0;
	cout << "\nEnter size of the array : ";
	cin >> size;
	int* inArray = new int[size];
	cout << "\nEnter elements of an array : \n";
	for (int i = 0; i < size; i++)
	{
		cin >> inArray[i];
	}
	int* resizedArray = resizeArray(inArray, size);
	cout << "\n\nResized Array : \n\n";
	for (int i = 0; i < size * 2; i++)
	{
		cout << resizedArray[i] << "  ";
	}
	delete[] inArray;
	inArray = nullptr;
	delete[] resizedArray;
	resizedArray = nullptr;
	cout << "\n\n";
	return 0;
}