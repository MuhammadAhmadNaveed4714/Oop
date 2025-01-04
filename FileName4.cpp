#include<iostream>
using namespace std;
class b1
{
private:
	int bb1;
public:
	b1()
	{
		cout << "\nb1 default constructor called.\n ";
		bb1 = -10;
	}
	b1(int num)
	{
		cout << "\nb1 overloaded constructor called.\n ";
		bb1 = num;
	}
	void display()
	{
		cout << "\nImplementing display function of b1 class.\n";
		cout << "bb1 : " << bb1;
	}
	~b1()
	{
		cout << "\nb1 destructor called.\n";
	}
};
class b2
{
private:
	int bb2;
public:
	b2()
	{
		cout << "\nb2 default constructor called.\n ";
		bb2 = -20;
	}
	b2(int num)
	{
		cout << "\nb2 overloaded constructor called.\n ";
		bb2 = num;
	}
	void display()
	{
		cout << "\nImplementing display function of b2 class.\n";
		cout << "bb2 : " << bb2;
	}
	~b2()
	{
		cout << "\nb2 destructor called.\n";
	}
};
class d:public b1,public b2
{
private:
	int d1;
public:
	d():b1(),b2()
	{
		cout << "\nd default constructor called.\n ";
		d1 = -10;
	}
	d(int num,int num1,int num2):b1(num1),b2(num2)
	{
		cout << "\nd overloaded constructor called.\n ";
		d1 = num;
	}
	void display()
	{
		cout << "\nImplementing display function of d class.\n";
		b1::display();
		b2::display();
		cout << "\nd1 : " << d1;
	}
	~d()
	{
		cout << "\nd destructor called.\n";
	}
};
int main()
{
	d s1(400, 500, 600);
	cout << "\n---";
	s1.display();
	cout << "\n---";
	s1.b1::display();
	cout << "\n---";
	s1.b2::display();
	cout << "\n---";
	return 0;
}