#include<iostream>
using namespace std;
// Function to find max difference
int maxAbsDiff(int arr[], int size)
{
	int* ls=new int [size];
	int* rs=new int[size];
	//find left nsmaller elements
	ls[0] = 0;
	for (int i = 1; i < size; i++)
	{
		int j = i - 1;
		while (j >= 0 && arr[j] >= arr[i])
		{
			j--;
		}
		if (j >= 0)
		{
			ls[i] = arr[j];
		}
		else
		{
			ls[i] = 0;
		}
	}
	//find right smaller elements
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
			rs[i] = arr[i];
		}
		else
		{
			rs[i] = 0;
		}
	}
	//calculate the maximum absolute difference
	int maxdiff = 0;
	for (int i = 0; i < size; i++)
	{
		int diff = abs(ls[i] - rs[i]);
		if (diff > maxdiff)
		{
			maxdiff = diff;
		}
	}
	delete[]ls;
	ls = nullptr;
	delete[]rs;
	rs = nullptr;
	return maxdiff;
}
int main()
{
	int arr[] = { 2,4,8,7,7,9,3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "\n\nMaximum absolute difference : " << maxAbsDiff(arr, size) << "\n";
	return 0;
}