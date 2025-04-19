#include<iostream>
using namespace std;
// Function to calculate the smallest left-most digit
void leftMostSmall(int* arr,int size)
{

	int *ls = new int[size];
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
	cout<<"\n\nLeft-most smallest array : ";
	for (int i = 0; i < size; i++)
	{
		cout << ls[i] << " ";
	}
	cout << "\n\n";
	delete[]ls;
	ls = nullptr;
}
int main()
{
	int arr[] = {4,2,8,7,9};
	int size = sizeof(arr) / sizeof(arr[0]);
	leftMostSmall(arr,size);
	return 0;
}