#include<iostream>
using namespace std;
//Function to check if an array is sorted in non-decreasing order
bool isSortedArray(int* inArray, const int size)
{
	//Check if the array is empty or contains only one element
	if (size <= 1)
	{
		return true;//An empty or single-element is considered sorted
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (inArray[i] > inArray[i + 1])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int array1[] = { 1,3,7,13 };
	int size1 = sizeof(array1) / sizeof(array1[0]);
	int array2[] = { 1,2,-1,3,5,4 };
	int size2 = sizeof(array2) / sizeof(array2[0]);
	cout << "\nInput Array : \n";
	for (int i=0; i < size1; i++)
	{
		cout << array1[i] << " ";
	}
	cout << "\n";
	cout << "\nOutput : "<<(isSortedArray(array1,size1)?"true":"false")<<"\n";
	cout << "\nInput Array : \n";
	for (int i = 0; i < size2; i++)
	{
		cout << array2[i] << " ";
	}
	cout << "\n";
	cout << "\nOutput : " << (isSortedArray(array2, size2) ? "true" : "false") << "\n";
	return 0;
}