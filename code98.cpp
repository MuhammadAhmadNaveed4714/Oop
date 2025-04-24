#include<iostream>
using namespace std;
const int MAX = 100;
// Function to implement the sieve of eretosthenes algorithm
void sieveOfEratosthenes(bool prime[])
{
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i * i < MAX; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j < MAX; j += i)
			{
				prime[j] = false;
			}
		}
	}
}
// Function to check if a number is a circular prime
bool isCircularPrime(int n, bool prime[])
{
	int num = n;
	int digits = 0;
	int temp = n;
	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}
	for (int i = 0; i < digits; i++)
	{
		if (!prime[num])
		{
			return false;
		}
		int lastDigit = num % 10;
		num = (num / 10) + (lastDigit * pow(10, digits - 1));
	}
	return true;
}
int main()
{
	bool prime[MAX];
	for (int i = 0; i < MAX; i++)
	{
		prime[i] = true;
	}
	sieveOfEratosthenes(prime);
	int count = 0;
	for (int i = 2; i < MAX; i++)
	{
		if (prime[i] && isCircularPrime(i, prime))
		{
			count++;
		}
	}
	cout << "\n\nNumber of circular primes below one hundred :  " << count << "\n\n";
	return 0;
}