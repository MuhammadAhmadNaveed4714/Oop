#include<iostream>
using namespace std;
// Function to reverse a number 
int reverse(int n)
{
	int no = 0;
	while (n != 0)
	{
		no = (no * 10) + (n % 10);
		n = n / 10;
	}
	return no;
}
int main()
{
	int v = 0;
	cout << "\nEnter a number : ";
	cin >> v;
	cout << "\n\n\t\t\t\t\tThe given number : " << v;
	v = reverse(v);
	cout << "\n\n\t\t\t\t\tIt's reverse is  : " << v << "\n\n";
	return 0;
}