#include<iostream>
using namespace std;
//Function to resize an array dynamically
int* resizeArray(int* inArray, const int size)
{
	//Dynamically allocate a new array with doublr the size
	int* newArray = new int[size * 2];
	//Copy elements from the original array to the new array
	for (int i = 0; i < size; i++)
	{
		newArray[i] = inArray[i];
	}
	//Fill second half of the new array with twice the values
	for (int i = size; i < size * 2; i++)
	{
		newArray[i] = inArray[i - size] * 2;
	}
	//Return the new Array
	return newArray;
}
int main()
{
	int size = 0;
	cout << "\nEnter size of the array : ";
	cin >> size;
	//Dynamically allocate an array
	int* array = new int[size];
	cout << "\n\t\t\t\t\tEnter elements of an array : \n";
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
	//Resize the array
	int* resizedArray = resizeArray(array, size);
	cout << "\n\t\t\t\t\tResized Array : \n";
	for (int i = 0; i < size * 2; i++)
	{
		cout << resizedArray[i] << "  ";
	}
	cout << "\n";
	//Deallocate memory
	delete[]array;
	array = nullptr;
	delete[]resizedArray;
	resizedArray = nullptr;
	return 0;
}