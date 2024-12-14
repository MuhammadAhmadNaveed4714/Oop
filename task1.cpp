#include<iostream>
#include<string>
using namespace std;
class sum
{
private:
	int x;
	int y;
public:
	sum() : x(0),y(0)
	{ }
	sum(int a,int b) : x(a), y(b)
	{ }
	void display()
	{
		cout << "\nDisplay : \n";
		cout << "\tx = " << x << "\t,\ty = " << y << "\n";
	}
	void setC(int a,int b)
	{
		x = a;
		y = b;
	}
	sum operator +=(const sum &right)
	{
		x += right.x;
		y += right.y;
		return* this;
	}
};
int main()
{
	sum s1, s2;
	s1.display();
	s2.display();
	s1.setC(12, 13);
	s2.setC(19, 21);
	s1.display();
	s2.display();
	s1 += s2;
	s1.display();
	s2.display();
	return 0  ;
}