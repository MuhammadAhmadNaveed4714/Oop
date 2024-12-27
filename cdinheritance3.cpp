//#include<iostream>
//#include<string>
//using namespace std;
//class Address
//{
//private:
//	string street;
//	string city;
//	string state;
//	string zip;
//public:
//	Address()
//	{
//		cout << "\nDefault Address constructor called.\n";
//		street = "";
//		city = "";
//		state = "";
//		zip = "";
//	}
//	Address(string s, string c, string st, string z)
//	{
//		cout << "\nParametrized Address constructor called.\n";
//		street = s;
//		city = c; state = st;
//		zip = z;
//	}
//	void displayAddress()
//	{
//		cout << "\nStreet : " << street;
//		cout << "\nCity : " << city;
//		cout << "\nState : " << state;
//		cout << "\nZip : " << zip << "\n";
//	}
//};
//class Person
//{
//private:
//	string name;
//	int age;
//	Address address;
//public:
//	Person()
//	{
//		cout << "\nDefault Person constructor called.\n";
//		name = "";
//		age = 0;
//		address;
//	}
//	Person(string n, int a, Address ad)
//	{
//		cout << "\nParametrized Person constructor called.\n";
//		name = n;
//		age = a;
//		address = ad;
//	}
//	void displayPerson()
//	{
//		cout << "\nName : " << name;
//		cout << "\nAge : " << age;
//		cout << "\nAddress : ";
//		address.displayAddress();
//	}
//};
//
//int main()
//{
//	Address ad("12", "23", "34", "56");
//	ad.displayAddress();
//	Person p("John Doe", 30, ad);
//	p.displayPerson();
//	
//
//	return 0;
//}