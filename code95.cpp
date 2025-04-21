#include<iostream>
using namespace std;
// Function to find right smaller elements
void Right(int* arr, int size)
{
	int* rs = new int[size];
	rs[size - 1] = 0;
	for (int i = size - 2; i >= 0; i--)
	{
		int j = i + 1;
		while (j < size && arr[j] >= arr[i])
		{
			j++;
		}
		if (j < size)
		{
			rs[i] = arr[j];
		}
		else
		{
			rs[i] = 0;
		}
	}
	cout << "\n\t\t\t\t\tDisplay of right-most array of elements : ";
	for (int i = 0; i < size; i++)
	{
		cout << rs[i] << " ";
	}
	cout << "\n";
	delete[]rs;
	rs = nullptr;
}
	int main()
	{
		int arr[] = { 4,2,8,7,9 };
		int size = sizeof(arr) / sizeof(arr[0]);
		Right(arr, size);
		return 0;
	}