#include<iostream>
using namespace std;
//Function for linear search
int linearSearch(int array[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (array[i] == key)
		{
			return i;//retyrn the index of the key
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
	cout << "\nOriginal Array : \n\n";
	printArray(array, n);
	int key = 0;
	cout << "\nEnter key to search : ";
	cin >> key;
	int result = linearSearch(array, n, key);
	if (result != -1)
	{
		cout << "\nKey found at index " << result << " using Linear search.\n";
	}
	else
	{
		cout << "\nKey not found using Linear search.\n";
	}
		return 0;
}