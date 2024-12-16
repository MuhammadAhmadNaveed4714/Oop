#include<iostream>
using namespace std;
class division
{
private:
	int num;
public:
	division():num(0)
	{ }
	division(int n) :num(n)
	{ }
	void setNumber(int x)
	{
		num = x;
	}
	int getNumber() const
	{
		return num;
	}
	void display() const
	{
		cout << "\nNumber : " << num << "\n";
	}
	division operator /= (const division& right)
	{
		num /= right.num;
		return *this;
	}
};
int main()
{
	division d1(6), d2(3);
	cout << "\n\nBefore Division : \n";
	d1.display();
	d2.display();
	d1 /= d2;
	cout << "\n\nAfter Division : \n";
	d1.display();
	d2.display();
	return 0;
}