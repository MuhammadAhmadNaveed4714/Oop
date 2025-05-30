#include<iostream>
using namespace std;
class grandfather
{
private:
	int num1;
public:
	grandfather()
	{
		cout << "\nGrandfather default constructor called.\n";
		num1 = 1;
    }
	grandfather(int n1)
	{
		cout << "\nGrandfather overloaded constructor called.\n";
		num1 = n1;
	}
	virtual void display()
	{
		cout << "\nInside display function of Grandfather.\n";
		cout << "\nAge : " << num1 << "\n";
	}
	~grandfather()
	{
		cout << "\nGrandfather destructor called.\n";
	}
};
class father:virtual public grandfather
{
private:
	int num2;
public:
	father()
	{
		cout << "\nFather default constructor called.\n";
		num2 = 2;
	}
	father(int n1,int n2):grandfather(n1)
	{
		cout << "\nFather overloaded constructor called.\n";
		num2 = n2;
	}
	virtual void display()
	{
		cout << "\nInside display function of Father.\n";
		cout << "\nAge : " << num2 << "\n";
	}
	~father()
	{
		cout << "\nFather destructor called.\n";
	}
};
class son :public father
{
private:
	int num3;
public:
	son():father()
	{
		cout << "\nSon default constructor called.\n";
		num3 = 3;
	}
	son(int n1,int n2,int n3):grandfather(n1),father(n1,n2)
	{
		cout << "\nSon overloaded constructor called.\n";
		num3 = n3;
	}
	 void display()
	{
		grandfather::display();
		father::display();
		cout << "\nInside display function of Son.\n";
		cout << "\nAge : " << num3 << "\n";
	}
	~son()
	{
		cout << "\nSon destructor called.\n";
	}
};
int main()
{
	grandfather* vp = nullptr;
	int n1 = 0;
	cout << "\nEnter 1 for grandfather,2 for father and 3 for son :  ";
	cin >> n1;
	if (n1 == 1)
	{
		vp = new grandfather(90);
		vp->display();
	}
	else if (n1 == 2)
	{
		vp = new father();
		vp->display();
	}
	else if (n1 == 3)
	{
		vp = new son();
		vp->display();
	}
	else
	{
		cout << "\nYou have entered wrong value.\n";
	}
	delete vp;
	vp = nullptr;
	return 0;
}