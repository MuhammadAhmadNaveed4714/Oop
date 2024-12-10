#include<iostream>
using namespace std;
class difference
{
private:
	int dig;
public:
	difference(int c = 1)
	{
		 dig = c;
	}
	void set(int c)
	{
		dig = c;
	}
	void display()
	{
		cout << "\nDisplay : " << dig << "\n";
	}
	difference operator - (const difference& g)
	{
		difference temp;
		temp.dig = dig - g.dig;
		return temp;
	}
};
int main()
{ 
	difference s1, s2, s3;
	s1.set(56);
	s2.set(34);
	s3 = s1 - s2;
	s3.display();
	return 0;
}