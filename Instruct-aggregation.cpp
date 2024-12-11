#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include<iostream>
#include<string>
using namespace std;
class Instructor
{
private:
	string lastName;
	string firstName;
	string officeNumber;
public:
	Instructor()
	{
		lastName = " ";
		firstName = " ";
		officeNumber = " ";
	}
	Instructor(string lname, string fname, string office)
	{
		lastName = lname;
		firstName = fname;
		officeNumber = office;
	}
	void set(string lname, string fname, string office)
	{
		lastName = lname;
		firstName = fname;
		officeNumber = office;
	}
	void print() const
	{
		cout << "\nLast Name : " << lastName;
		cout << "\nFirst Name : " << firstName;
		cout << "\noffice Number : " << officeNumber;
	}
};
#endif