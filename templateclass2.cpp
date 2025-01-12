#include<iostream>
using namespace std;
template<typename t>
t add(t n1, t n2)
{
	t n3 = n1 + n2;
	return n3;
}
int main()
{
	 int cl1=0,cl2=0;
	 cout << "\nEnter the values for first number (int) :  ";
	 cin >> cl1;
	 cout << "\nEnter the values for second number (int) :  ";
	 cin >> cl2;
	 cout << "\nTheir sum in int is " << add(cl1, cl2) << "\n";
	 cout << "\n-----------------------------------------\n";
	 double dl1 = 0, dl2 = 0;
	 cout << "\nEnter the values for first number (double) :  ";
	 cin >> dl1;
	 cout << "\nEnter the values for second number (double) :  ";
	 cin >> dl2;
	 cout << "\nTheir sum in double is " << add(dl1, dl2) << "\n";
	return 0;
}