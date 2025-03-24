#include<iostream>
using namespace std;
// Struct Node
struct node
{
	int data;
	node* next;
};
//Function to print a node structure
void display(node* head)
{
	cout << "\n\tDisplay of desired node structure : ";
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}
//Function to remove a node structure
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
	node* head = new node{ 30 };
	head->next = new node{ 35 };
	head->next->next = new node{ 40 };
	head->next->next->next = new node{ 45 };
	head->next->next->next->next = new node{ 50 };
	head->next->next->next->next->next = new node{ 55 };
	head->next->next->next->next->next->next = new node{ 60 };
	head->next->next->next->next->next->next->next = new node{ 65 };
	head->next->next->next->next->next->next->next->next = new node{ 70 };
	display(head);
	remove(head);
	head = nullptr;
	return 0;
}