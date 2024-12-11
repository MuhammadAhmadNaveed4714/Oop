#include<iostream>
#include<string>
#include"Corse-aggregation.cpp"
using namespace std;
int main()
{
	cout << "\n\n";
	Corse myCourse("Object Oriented Programming",
		"Sahiba", "Mam Madiha",  "RH3010",
		"Starting out with C++", "Tony Gaddis", "Addison Wesley");
	myCourse.print();
	cout << "\n\n";
	return 0;
}