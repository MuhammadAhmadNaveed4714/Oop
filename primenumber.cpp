#include<iostream>
using namespace std;
bool isPrime(int num)
{
	if (num <= 1)
	{
		return false;
	}
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int num = 0;
	cout << "\n\t\t\t\t\t\tEnter a number : ";
	cin >> num;
	if (isPrime(num))
	{
		cout <<"\n\t\t\t\t\t\t" << num << " is a prime number.\n";
	}
	else
	{
		cout <<"\n\t\t\t\t\t\t" << num << " is not a prime number.\n";
	}
	return 0;
}