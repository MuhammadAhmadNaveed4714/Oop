#include<iostream>
using namespace std;
// Struct node
struct node
{
	int data;
	node* next;
};
// Function to insert a node in linked list
void insert(node** head, int data)
{
	node* newnode = new node();
	newnode->data = data;
	newnode->next = nullptr;
	while (*head == nullptr)
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
// Function to delete a node in linked list
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
	return 0;
}