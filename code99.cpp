#include<iostream>
using namespace std;
// Function to check if a number is prime or not
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
// Function to calculate the number of digits in a number
int countDigits(int n)
{
	int digits = 0;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return digits;
}
// Function to calculate the power of 10
int powerOf10(int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result *= 10;
	}
	return result;
}
// Function to check if a number is a circular prime or not
bool isCircularPrime(int n)
{
	int num = n;
	int digits = countDigits(n);
	for (int i = 0; i < digits; i++)
	{
		if (!isPrime(num))
		{
			return false;
		}
		int lastDigit = num % 10;
		num = (num / 10) + (lastDigit * powerOf10(digits - 1));
	}
	return true;
}
int main()
{
	int num = 0;
	cout << "\nEnter a number (1 - 4 digits) : ";
	cin >> num;
	if (num >= 1 && num <= 9999)
	{
		if (isCircularPrime(num))
		{
			cout << "\n" << num << " is a circular prime.\n";
		}
		else
		{
			cout << "\n" << num << " is not a circular prime.\n";
		}
	}
	else
	{
		cout << "\nPlease enter a number between 1 and 9999.\n";
	}
	return 0;
}