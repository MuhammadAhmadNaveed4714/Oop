#include<iostream>
using namespace std;
class grandparents
{
private:
	int num1;
public:
	grandparents()
	{
		cout << "\nGrandparents default constructor called.\n";
		num1 = 0;
	}
	grandparents(int n)
	{
		cout << "\nGrandparents overloaded constructor called.\n";
		num1 = n;
	}
	void display()
	{
		cout << "\nInside display function of grandparents.\n";
		cout << "\nGrandparents' num : " << num1;
	}
	~grandparents()
	{
		cout << "Grandparents destructor called.\n";
	}
};
class Father:virtual public grandparents
{
private:
	int num2;
public:
	Father()
	{
		cout << "\nFather default constructor called.\n";
		num2 = 0;
	}
	Father(int n,int y):grandparents(n)
	{
		cout << "\nFather overloaded constructor called.\n";
		num2 = y;
	}
	void display()
	{
		cout << "\nInside display function of father.\n";
		cout << "\nFather's num : " << num2;
	}
	~Father()
	{
		cout << "Father destructor called.\n";
	}
};
class Mother : virtual public grandparents
{
private:
	int num3;
public:
	Mother()
	{
		cout << "\nMother default constructor called.\n";
		num3 = 0;
	}
	Mother(int y,int n):grandparents(y)
	{
		cout << "\nMother overloaded constructor called.\n";
		num3 = n;
	}
	void display()
	{
		cout << "\nInside display function of mother.\n";
		cout << "\nMother's num : " << num3;
	}
	~Mother()
	{
		cout << "Mother destructor called.\n";
	}
};
class Child : public Father,public Mother
{
private:
	int num4;
public:
	Child() 
	{
		cout << "\nChild default constructor called.\n";
		num4 = 0;
	}
	Child(int w,int x,int y,int z)
	{
		cout << "\nChild overloaded constructor called.\n";
		num4 = z;
	}
	void display()
	{
		cout << "\nInside display function of child.\n";
		grandparents::display();
		Father::display();
		Mother::display();
		cout << "\nChild's num : " << num4;
	}
	~Child()
	{
		cout << "Child destructor called.\n";
	}
};
int main()
{
	Child c1;
	c1.display();
	cout << "\n---------------------\n";
	return 0;
}