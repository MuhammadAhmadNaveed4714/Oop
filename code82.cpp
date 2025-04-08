#include<iostream>
using namespace std;
int main()
{
	int n = 0;
	int t1 = 0;
	int t2 = 1;
	//Ask the user for the number of terms
	cout << "\nEnter the number of terms : ";
	cin >> n;
	//Print the first two terms
	cout << "\nFibonacci sequence : " << t1 << " , " << t2;
	//Print the remaining terms
	for (int i = 3; i <= n; i++)
	{
		int nextTerm = t1 + t2;
		cout << " , " << nextTerm;
		t1 = t2;
		t2 = nextTerm;
	}
	cout << "\n";
	return 0;
}