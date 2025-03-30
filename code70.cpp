#include<iostream>
using namespace std;
//Struct Node
struct node
{
	int x;
	int y;
	node* next;
};
//Calculating the area of a rectangle
int calculate(node* head)
{
	int minx = 100;
	int maxx = -100;
	int miny = 100;
	int maxy = -100;
	node* temp = head;
	while (temp != nullptr)
	{
		if (temp->x < minx)
		{
			minx = temp->x;
		}
		if (temp->x > maxx)
		{
			maxx = temp->x;
		}
		if (temp->y < miny)
		{
			miny = temp->y;
		}
		if (temp->y > maxy)
		{
			maxy = temp->y;
		}
		temp = temp->next;
	}
	int width = (maxx - minx);
	int length = (maxy - miny);
	return (width * length);
}
//Removal
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
	node* head = new node{ 8,6 };
	head->next = new node{ 4,7 };
	head->next->next = new node{ 9,8 };
	head->next->next->next = new node{ 2,4 };
	cout<<"\nCalculation : "<<calculate(head)<<"\n";
	remove(head);
	head = nullptr;
	return 0;
}