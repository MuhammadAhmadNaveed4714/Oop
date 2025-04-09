#include<iostream>
#include<string>
using namespace std;
struct student
{
	string name;
	int age;
};
int main()
{
	int numstudents = 0;
	student students[5];
	//Ask the user for the number of students
	do
	{
		cout << "\nEnter the number of students (1-25) : ";
		cin >> numstudents;
	} while (numstudents < 1 || numstudents > 25);
	//Read in the names and ages of the students
	for (int i = 0; i < numstudents; i++)
	{
		cout << "\nEnter the name of student" << i + 1 << " : ";
		cin >> students[i].name;
		int age = 0;
		do
		{
			cout << "\nEnter the age of student " << i + 1 << " : ";
			cin >> age;
		} while (age < 1);
		students[i].age = age;
	}
	//Sort the students by name and age
	for (int i = 0; i < numstudents - 1; i++)
	{
		for (int j = i + 1; j < numstudents; j++)
		{
			if (students[i].name > students[j].name)
			{
				student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
			else if (students[i].name == students[j].name)
			{
				if (students[i].age > students[j].age)
				{
					student temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
	}
	//Print the student at the front and end of the line
	cout << "\nThe student at the front of the line is : " << students[0].name << "\n";
	cout << "\nThe student at the end of the line is : " << students[numstudents - 1].name << "\n";
	return 0;
}