#include<iostream>
using namespace std;
// Struct node
struct node
{
	int data;
	node* next;
};
// Function to insert a node
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
	node* lastnode = *head;
	while (lastnode->next != nullptr)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = newnode;
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
}
// Function to calculate length of a node
int length(node* head)
{
	int count = 0;
	while (head != nullptr)
	{
		head = head->next;
		count++;
	}
	return count;
}
// Function to rotate a node to its left
node* rotateleft(node* head,int k)
{
	int len = length(head);
	node* curr = head;
	int count = 1;
	while (count < len - k)
	{
		curr = curr->next;
		count++;
	}
	node* ptr = curr->next;
	node* temp = ptr;
	curr->next = nullptr;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = head;
	return ptr;
}
int main()
{
	node* ntr = nullptr;
	// Inserting a node
	insert(&ntr, 1);
	insert(&ntr, 2);
	insert(&ntr, 3);
	insert(&ntr, 4);
	insert(&ntr, 5);
	// Printing a node
	cout << "\nOriginal List : ";
	print(ntr);
	ntr = rotateleft(ntr,2);
	cout << "\nModified List : ";
	print(ntr);
	remove(ntr);
	ntr = nullptr;
	return 0;
}