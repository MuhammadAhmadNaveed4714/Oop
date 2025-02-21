#include<iostream>
using namespace std;
void print(int* arr,int r,int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
int** matrix( int r, int c)
{
	int** m = new int* [r];
	for (int i = 0; i < r; i++)
	{
		m[i] = new int[c];
	}
	return m;
}
int** multiply(int r1, int c1,int r2,int c2,int** m,int** n)
{
	int **res=matrix(r1, c2);
	for (int i = 0; i < r1, i++)
	{
		for (int j = 0; j < c2; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < c1; k++)
			{
				res[i][j] += (m[i][k] *n[k][j]);
			}
		}
	}
	return res;
}
void input(int* arr, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin>>arr[i][j];
		}
	}
}

int dim()
{
	int n = 0;
	cin >> n;
	return n;
}
void p(const char* d)
{
	cout << "\nEnter number of " << d << " : ";
}
int** deallocate(int** arr,int r)
{
	for (int i = 0; i < r; i++)
	{
		delete[]arr[i];
		arr[i] = nullptr;
	}
	delete[]arr;
	arr = nullptr;
	return arr;
}
int main()
{
	return 0;
}