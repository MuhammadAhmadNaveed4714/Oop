#include<iostream>
using namespace std;
class roll
{
private:
	int num;
public:
	roll():num(0)
	{ }
	roll(int n) :num(n)
	{}
	void setRoll(int n)
	{
		num = n;
	}
	void display() const
	{
		cout << "\nValue of number : " << num;
	}
	roll operator*=(const roll& obj)
	{
		num *= obj.num;
		return *this;
	}
};
int main()
{
	roll r1, r2;
	r1.setRoll(10);
	r2.setRoll(20);
	cout << "\nBefore : \n";
	r1.display();
	r2.display();
	r1 *= r2;
	cout << "\nAfter : \n";
	r1.display();
	r2.display();
	cout << "\n";
	return 0;
}