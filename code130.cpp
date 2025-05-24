#include<iostream>
using namespace std;
// Struct node
struct node
{
	int data;
	node* next;
};
// Function to insert a node
void insert(node** head, int data)
{
	node* newnode = new node();
	newnode->data = data;
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
// Function to print a node
void print(node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}
// Function to remove a node
void remove(node* head)
{
	node* temp = nullptr;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	cout << "\n";
}
int main()
{
	node* t = nullptr;
	// inserting a node
	insert(&t, 133);
	insert(&t, 134);
	insert(&t, 135);
	insert(&t, 136);
	insert(&t, 137);
	insert(&t, 138);
	// printing  a node
	cout << "\n\t\t\t\t\tLinked List : ";
	print(t);
	// removing a node
	remove(t);
	t = nullptr;
	return 0;
}