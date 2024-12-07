//#include<iostream>
//#include<string>
//using namespace std;
//class StudentTestScores
//{
//private:
//	string studentName;
//	double* testScores;
//	int numTestScores;
//	void createTestScoresArray(int size)
//	{
//		testScores = new double[size];
//		for (int i = 0; i < size; i++)
//		{
//			testScores[i] = 0.0;
//		}
//	}
//public:
//	StudentTestScores(string name, int numScores)
//	{
//		studentName = name;
//		numTestScores = numScores;
//		createTestScoresArray(numScores);
//	}
//	StudentTestScores(const StudentTestScores& obj)
//	{
//		studentName = obj.studentName;
//		numTestScores = obj.numTestScores;
//		testScores = new double[numTestScores];
//		for (int i = 0; i < numTestScores; i++)
//		{
//			testScores[i] = obj.testScores[i];
//		}
//	}
//	void setTestScore(double score, int index)
//	{
//		testScores[index] = score;
//	}
//	void setStudentName(string name)
//	{
//		studentName = name;
//	}
//	string getStudentName() const
//	{
//		return studentName;
//	}
//	int getNumTestScores()
//	{
//		return numTestScores;
//	}
//	double getTestScore(int index) const
//	{
//		return testScores[index];
//	}
//	void operator=(const StudentTestScores& right)
//	{
//		delete[] testScores;
//		testScores = nullptr;
//		studentName = right.studentName;
//		numTestScores = right.numTestScores;
//		testScores = new double[numTestScores];
//		for (int i = 0; i < numTestScores; i++)
//		{
//			testScores[i] = right.testScores[i];
//		}
//	}
//	void displayStudent()
//	{
//		cout << "Name : " << getStudentName() << endl;
//		cout << "Test Scores : ";
//		for (int i = 0; i < getNumTestScores(); i++)
//		{
//			cout << getTestScore(i) << " ";
//		}
//		cout << endl;
//	}
//	~StudentTestScores()
//	{
//		delete[] testScores;
//		testScores = nullptr;
//	}
//};
//void displayStudent(StudentTestScores);
//int main()
//{
//	StudentTestScores student1("Kelly Thorton", 3);
//	student1.setTestScore(100.0, 0);
//	student1.setTestScore(95.0, 1);
//	student1.setTestScore(80, 2);
//	student1.displayStudent();
//	StudentTestScores student2("Jimmy Griffin", 5); student2.displayStudent();
//	student2 = student1;
//	student1.displayStudent();
//	student2.displayStudent();
//	return 0;
//}

















//#include<iostream>
//#include<string>
//using namespace std;
//class STS
//{
//private:
//	string name;
//	int numScores;
//	int* testScores;
//	void createArray(int size)
//	{
//		testScores = new int[size];
//		for (int i = 0; i < size; i++)
//		{
//			testScores[i] = 0;
//		}
//	}
//public:
//	STS(string n, int no)
//	{
//		name = n;
//		numScores = no;
//		createArray(numScores);
//	}
//	STS(const STS& obj)
//	{
//		name = obj.name;
//		numScores = obj.numScores;
//		testScores = new int[numScores];
//		for (int i = 0; i < numScores; i++)
//		{
//			testScores[i] = obj.testScores[i];
//		}
//	}
//	void setTestScore(int ind, int sco)
//	{
//		testScores[ind] = sco;
//	}
//	int getTestScore(int in) const
//	{
//		return testScores[in];
//	}
//	void operator= (const STS& right)
//	{
//		delete[] testScores;
//		testScores = nullptr;
//		name = right.name;
//		numScores = right.numScores;
//		testScores = new int[numScores];
//		for (int i = 0; i < numScores; i++)
//		{
//			testScores[i] = right.testScores[i];
//		}
//	}
//	void display()
//	{
//		cout << "\nName : " << name;
//		cout << "\nNumbers : " << numScores;
//		cout << "\nTest Scores : ";
//		for (int i = 0; i < numScores; i++)
//		{
//			cout << getTestScore(i) << " ";
//		}
//		cout << endl;
//	}
//	~STS()
//	{
//		delete[] testScores;
//		testScores = nullptr;
//	}
//};
//int main()
//{
//	int pu = 0;
//	STS s1("M.Ahmad", 5);
//	cout << "S1 display : ";
//	s1.display();
//	for (int i = 0; i < 5; i++)
//	{
//		cout << "Enter test score " << i + 1 << " : ";
//		cin >> pu;
//		s1.setTestScore(i, pu);
//	}
//	cout << "S1 display (2) : ";
//	s1.display();
//	STS s2("Gillani", 3);
//	cout << "S2 display : ";
//	s2.display();
//	s2 = s1;
//	cout << "S1 display (2) : ";
//	s2.display();
//	return 0;
//}

