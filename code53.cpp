#include<iostream>
#include<string>
using namespace std;
struct Teacher
{
	int teacherId;
	string name;
	int noOfCourses;
	string* courses;
};
//Function to get teacher's information from user
void getTeacherInfo(Teacher& teacher)
{
	cout << "\nEnter teacher's Id : ";
	cin >> teacher.teacherId;
	cout << "\nEnter teacher's name : ";
	cin.ignore();
	getline(cin, teacher.name);
	cout << "\nEnter number of courses : ";
	cin >> teacher.noOfCourses;
	teacher.courses = new string[teacher.noOfCourses];
	for (int i = 0; i < teacher.noOfCourses; i++)
	{
		cout << "Enter course " << i + 1 << " : ";
		cin.ignore();
		getline(cin, teacher.courses[i]);
	}
}
//Function to print teacher's information
void printTeacherInfo(const Teacher& teacher)
{
	cout << "\nTeacher's ID : " << teacher.teacherId;
	cout << "\nTeacher's name : " << teacher.name;
	cout << "\nNumber of courses : " << teacher.noOfCourses;
	cout << "\nCourses : ";
	for (int i = 0; i < teacher.noOfCourses; i++)
	{
		cout <<"\n" << teacher.courses[i];
	}
}
int main()
{
	Teacher teacher;
	getTeacherInfo(teacher);
	printTeacherInfo(teacher);
	delete[] teacher.courses;
	teacher.courses = nullptr;
	return 0;
}