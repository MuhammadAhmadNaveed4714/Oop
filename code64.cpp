#include<iostream>
using namespace std;
template <typename t>
void swapValues(t& a, t& b)
{
	t te = a;
	a = b;
	b = te;
}
int main()
{
	int x = 5, y = 10;
	cout << "\n\n\t\t\tBefore swapping : \n";
	cout << "\nX : " << x;
	cout << "\nY : " << y;
	swapValues(x, y);
	cout << "\n\n\t\t\tAfter  swapping : \n";
	cout << "\nX : " << x;
	cout << "\nY : " << y<<"\n";
	return 0;
}