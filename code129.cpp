#include<iostream>
using namespace std;
// Struct node
struct node
{
	int data;
	node* next;
};
// Function to insert a node in limnked list
void insert(node** head, int d)
{
	node* newnode = new node();
	newnode->data = d;
	newnode->next = nullptr;
	if (*head == nullptr)
	{
		*head = newnode;
		return;
	}
	node* last = *head;
	while (last->next != nullptr)
	{
		last = last->next;
	}
	last->next = newnode;
}
// Function to print a linked list
void print(node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}
// Function to remove a node in linked list
void remove(node* head)
{
	node* temp = nullptr;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}
int main()
{
	node* man = nullptr;
	// Inserting nodes in the linked list
	insert(&man, 12);
	insert(&man, 13);
	insert(&man, 14);
	insert(&man, 15);
	insert(&man, 16);
	// Printing of linked list
	cout << "\n\t\t\t\t\tLinked List : ";
	print(man);
	// Removing of linked list
	remove(man);
	man = nullptr;
	return 0;
}