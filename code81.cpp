#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int numFlips = 0;
	int heads = 0;
	int tails = 0;
	//Seed the random number generator
	srand(time(0));
	//Ask the user for the number of coin flips
	cout << "\nEnter number of coin flips : ";
	cin >> numFlips;
	//Simulate the coin flips
	for (int i = 0; i < numFlips; i++)
	{
		//Generate a random number (0 or 1)
		int flip = rand() % 2;
		//If the number is 0,it is tail.
		//Otherwise,it is head.
		if (flip == 0)
		{
			tails++;
		}
		else
		{
			heads++;
		}
	}
	//Print the results
	cout << "\nNumber of flips : " << numFlips << "\n";
	cout << "\nNumber of heads : " << heads << "\n";
	cout << "\nNumber of tails : " << tails << "\n";
	return 0;
}