#include<iostream>
using namespace std;
// function to calculate power of 10
int p10(int di)
{
	int result = 1;
	for (int i = 1; i <= di; i++)
	{
		result *= 10;
	}
	return result;
}
// function to check nif a number is prime or not
bool isPrime(int n)
{
	if (n <= 1)
	{
		return false;
	}
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int c = 0;
	cout << "\nEnter a number : ";
	cin >> c;
	int po = 0;
	cout << "\nGive me power : ";
	cin >> po;
	cout << "\nThe desired powerful number : " << p10(po) << "\n";
	cout << "\nIs the number prime or not : ";
	if (isPrime(c))
	{
		cout << "Prime\n";
	}
	else
	{
		cout << "Not a prime\n";
	}
	return 0;
}