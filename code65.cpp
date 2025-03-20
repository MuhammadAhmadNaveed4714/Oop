#include<iostream>
using namespace std;
int main()
{
	cout << "\t\t\t\t\tStrengthening the Concepts of pointers \n";
	int x = 10;
	int* ptr = &x;
	int* str = ptr;
	int** ctr = &ptr;
	cout << "\n1-x	:	" << x;
	cout << "\n2-&x	:	" << &x;
	cout << "\n3-*ptr	:	" << *ptr;
	cout << "\n4-ptr	:	" << ptr;
	cout << "\n5-&ptr	:	" << &ptr;
	cout << "\n6-*str	:	" << *str;
	cout << "\n7-str	:	" << str;
	cout << "\n8-&str	:	" << &str;
	cout << "\n1-**ctr	:	" << **ctr;
	cout << "\n0-*ctr	:	" << *ctr;
	cout << "\n2-&ctr	:	" << &ctr << "\n";
	return 0;
}