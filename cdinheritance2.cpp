#include<iostream>
#include<string>
using namespace std;
class Address
{
private:
	string street;
	string city;
	string state;
	string zip;
public:
	Address()
	{
		street = "";
		city = ""; 
		state = "";
		zip = "";
	}
	Address(string s, string c, string st, string z)
	{
		street = s;
		city = c; state = st;
		zip = z;
	}
	void displayAddress()
	{
		cout << "\nStreet : " << street;
		cout << "\nCity : " << city;
		cout << "\nState : " << state;
		cout << "\nZip : " << zip<<"\n";
	}
};
class Person
{
private:
	string name;
	int age;
	Address address;
public:
	Person(string n, int a, Address ad)
	{
		name = n;
		age = a;
		address = ad;
	}
	void displayPerson()
	{
		cout << "\nName : " << name;
		cout << "\nAge : " << age;
		cout << "\nAddress : ";
		address.displayAddress();
	}
};
int main()
{
	Address ad;
	Person p("John Doe", 30, ad);
	p.displayPerson();
	return 0;
}