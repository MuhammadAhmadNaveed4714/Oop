#include<iostream>
#include<cmath>
using namespace std;
//node structure
struct node
{
	double x;
	double y;
	node* next;
};
//function to calculate the area of a rectangle
int calculateArea(node* head)
{
	//initialize variables to store the minimum and maximum x and y coordinates
	double minX = INFINITY;
	double maxX = -INFINITY;
	double minY = INFINITY;
	double maxY = -INFINITY;
	//traverse the linked list to find the minimum and maximum x and y coordinates
	node* temp=head;
	while (temp != nullptr)
	{
		minX = min(minX, temp->x);
		maxX = max(maxX, temp->x);
		minY = min(minY, temp->y);
		maxY = max(maxY, temp->y);
		temp = temp->next;
	}
	//Calculate the width and height of a rectangle
	double width = abs(maxX - minX);
	double height = abs(maxY - minY);
	//Return the area of a rectangle
	return static_cast<int>(width * height);
}
void remove(node* head)
{
	while (head != nullptr)
	{
		node* temp = head;
		head = head->next;
		delete temp;
	}
}
int main()
{
	//create a sample linked list : (0,0)->(4,0)->(4,3)->(0,3)->NULL
	node* head = new node{0,0};
	head->next = new node{ 4,0 };
	head->next->next = new node{ 4,3 };
	head->next->next->next = new node{ 0,3 };
	cout << "\nArea of a rectangle : " << calculateArea(head) << "\n";
	remove(head);
	head = nullptr;
	return 0;
}