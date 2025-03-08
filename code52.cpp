#include<iostream>
#include<string>
using namespace std;
struct FoodItem
{
	string name;
};
struct FoodStall
{
	int stallNumber;
	string restaurantName;
	int numVisitors;
	int numFooditems;
	FoodItem* foodItems;
};
//Function to populate the array of structures
void populateArray(FoodStall* stalls, int numStalls)
{
	for (int i = 0; i < numStalls; i++)
	{
		cout << "\nEnter stall number : ";
		cin >> stalls[i].stallNumber;
		cout << "\nEnter restaurant name : ";
		cin.ignore();
		getline(cin, stalls[i].restaurantName);
		cout << "\nEnter number of visitors : ";
		cin >> stalls[i].numVisitors;
		cout << "\nEnter number of food items : ";
		cin >> stalls[i].numFooditems;
		stalls[i].foodItems = new FoodItem[stalls[i].numFooditems];
		for (int j = 0; j < stalls[i].numFooditems; j++)
		{
			cout << "\nEnter food item name : ";
			cin.ignore();
			getline(cin, stalls[i].foodItems[j].name);
		}
	}
}
//Function to display all stalls
void showAllStalls(FoodStall* stalls, int numStalls)
{
	for (int i = 0; i < numStalls; i++)
	{
		cout << "\nStall number : " << stalls[i].stallNumber ;
		cout << "\nRestaurant Name : " << stalls[i].restaurantName;
		cout << "\nNumber of visitors : " << stalls[i].numVisitors;
	}
}
//Function to search for a stall by name
void searchStall(FoodStall* stalls, int numStalls)
{
	string name;
	cout << "\nEnter restaurant name to search : ";
	cin.ignore();
	getline(cin, name);
	bool found = false;
	for (int i = 0; i < numStalls; i++)
	{
		if (stalls[i].restaurantName == name)
		{
			cout << "\nStall number : " << stalls[i].stallNumber;
			cout << "\nRestaurant name : " << stalls[i].restaurantName;
			cout << "\nNumber of visitors : " << stalls[i].numVisitors;
			cout << "\nFood Items : ";
			for (int j = 0; j < stalls[i].numFooditems; j++)
			{
				cout << stalls[i].foodItems[j].name << "\n";
			}
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "\nStall not found!\n";
	}
}
//Function to find the stall with the most visitors
FoodStall findMostVisitedStall(FoodStall* stalls, int numStalls)
{
	FoodStall mostVisited = stalls[0];
	for (int i = 1; i < numStalls; i++)
	{
		if (stalls[i].numVisitors > mostVisited.numVisitors)
		{
			mostVisited = stalls[i];
		}
	}
	return mostVisited;
}
int main()
{
	int numStalls = 0;
	cout << "\nEnter number of stalls : ";
	cin >> numStalls;
	FoodStall* stalls = new FoodStall[numStalls];
	populateArray(stalls, numStalls);

	FoodStall mostVisited; // Declare mostVisited here to ensure it is initialized properly

	while (true)
	{
		cout << "\n1-Show all stalls";
		cout << "\n2-Search for a stall";
		cout << "\n3-Find the stall with most visitors";
		cout << "\n4-Exit\n";
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			showAllStalls(stalls, numStalls);
			break;
		case 2:
			searchStall(stalls, numStalls);
			break;
		case 3:
			mostVisited = findMostVisitedStall(stalls, numStalls);  // Initialize inside the case
			cout << "\nStall number : " << mostVisited.stallNumber;
			cout << "\nRestaurant Name : " << mostVisited.restaurantName;
			cout << "\nNumber of visitors : " << mostVisited.numVisitors;
			break;
		case 4:
			delete[] stalls;
			stalls = nullptr;
			exit(0);
		default:
			cout << "\nInvalid Choice!\n";
		}
	}

	return 0;
}
