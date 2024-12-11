#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<string>
#include"Instruct-aggregation.cpp"
#include"TextBook-aggregation.cpp"
using namespace std;
class Corse
{
private:
	string courseName;
	Instructor instructor;
	Textbook textbook;
public:
	Corse(string course,
		string instrLastName, string instrFirstName, string instrOffice,
		string textTitle, string author, string publish)
	{
		courseName = course;
		instructor.set(instrLastName, instrFirstName, instrOffice);
		textbook.set(textTitle, author, publish);
	}
	void print() const
	{
		cout << "\nCourse Name : " << courseName;
		cout << "\nInstructor Information : ";
		instructor.print();
		cout << "\nTextbook Information : ";
		textbook.print();
	}
};
#endif
