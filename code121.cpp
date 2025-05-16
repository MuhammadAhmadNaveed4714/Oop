#include<iostream>
using namespace std;
// Struct node
struct node
{
	int data;
	node* next;
};
// Function to insert a node
void insert(node** head, int k)
{
	node* newnode = new node();
	newnode->data = k;
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
}
// Function to calculate a node
int calculatenode(node* head)
{
	int length = 0;
	while (head != nullptr)
	{
		length++;
		head = head->next;
	}
	return length;
}
int main()
{
	node* h = nullptr;
	insert(&h, 11);
	insert(&h, 22);
	insert(&h, 33);
	insert(&h, 44);
	insert(&h, 55);
	cout << "\n\t\t\t\t\tPrinting of a linked list : ";
	print(h);
	cout << "\n\t\t\t\t\tTotal number of nodes : " << calculatenode(h) << "\n";
	remove(h);
	h = nullptr;
	return 0;
}