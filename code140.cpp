#include<iostream>
using namespace std;
// struct node
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
	node* lastnode = *head;
	while (lastnode->next != nullptr)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = newnode;
}
// Function to print a node
void print(node* p)
{
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}
// Function to remove a node
void remove(node* p)
{
	node* temp = nullptr;
	while (p != nullptr)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
}
int main()
{
	node* h = nullptr;
	insert(&h, 10);
	insert(&h, 11);
	insert(&h, 12);
	insert(&h, 13);
	insert(&h, 14);
	cout << "\n Linked List : ";
	print(h);
	remove(h);
	h = nullptr;
	return 0;
}