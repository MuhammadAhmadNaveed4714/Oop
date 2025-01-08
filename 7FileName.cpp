#include<iostream>
using namespace std;
class father
{
private:
	int age;
public:
	father()
	{
		cout << "\nDefault father constructor called.\n";
		age = 50;
	}
	father(int n)
	{
		cout << "\nParametrized father constructor called.\n";
		age = n;
	}
	void display()
	{
		cout << "\nFather's age : " << age;
	}
	~father()
	{
		cout << "\nFather destructor called.\n";
	}
};
class mother
{
private:
	int age;
public:
	mother()
	{
		cout << "\nDefault mother constructor called.\n";
		age = 45;
	}
	mother(int n)
	{
		cout << "\nParametrized mother constructor called.\n";
		age = n;
	}
	void display()
	{
		cout << "\nMother's age : " << age;
	}
	~mother()
	{
		cout << "\nMother destructor called.\n";
	}
};
class child:public father,public mother
{
private:
	int age;
public:
	child()
	{
		cout << "\nDefault child constructor called.\n";
		age = 10;
	}
	child(int f,int m,int c):father(f),mother(m)
	{
		cout << "\nParametrized child constructor called.\n";
		age = c;
	}
	void display()
	{
		father::display();
		mother::display();
		cout << "\nChild's age : " << age<<"\n";
	}
	~child()
	{
		cout << "\nChild destructor called.\n";
	}
};
int main()
{
	child c1(45,40,12);
	c1.display();
	return 0;
}