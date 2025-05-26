#include<iostream>
using namespace std;
// Struct node
struct node
{
	int data;
	node* next;
};
// Function to insert a node in the linked list
void insert(node** head, int d)
{
	node* newnode = new node();
	newnode->data = d;
	newnode->next = nullptr;
	while (*head == nullptr)
	{
		*head = newnode;
		return;
	}
	node* lastnode= * head;
	while (lastnode->next != nullptr)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = newnode;
}
// Function to print a node in linked list
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
// Function to calculate length of a linked list
int length(node* h)
{
	int c = 0;
	while (h != nullptr)
	{
		c++;
		h = h->next;
	}
	return c;
}
// Function to rotate a linked list to right 
node* right(node* head, int k)
{
	node* temp = head;
	node* ptr = head;
	int len = length(head);
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = head;
	int c = 0;
	while (c < len - k - 1)
	{
		ptr = ptr->next;
		c++;
	}
	node* ntr = ptr->next;
	ptr->next = nullptr;
	return ntr;
}
int main()
{
	node* j = nullptr;
	// Inserting nodes in linked list
	insert(&j, 1);
	insert(&j, 2);
	insert(&j, 3);
	insert(&j, 4);
	insert(&j, 5);
	// Printing a linked list
	cout << "\nOriginal Linked list : ";
	print(j);
	// Rotating linked list to right
	j=right(j, 2);
	// Printing a linked list
	cout << "\n\nModified Linked list : ";
	print(j);
	// Removing a linked list
	remove(j);
	j = nullptr;
	return 0;
}