#include<iostream>
using namespace std;
// struct node
struct node
{
	int data;
	node* next;
};
// function to insert a node in linked list
void insert(node** h, int d)
{
	node* newnode = new node();
	newnode->data = d;
	newnode->next = nullptr;
	if (*h == nullptr)
	{
		*h = newnode;
		return;
	}
	node* lastnode = *h;
	while (lastnode->next != nullptr)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = newnode;
}
// function to print a node in linked list
void print(node* h)
{
	while (h != nullptr)
	{
		cout << h->data << " ";
		h = h->next;
	}
	cout << "\n";
}
// function to remove a linked list
void remove(node* h)
{
	node* temp = nullptr;
	while (h != nullptr)
	{
		temp = h;
		h = h->next;
		delete temp;
	}
}
// function to reverse a singly linked list
void reverse(node** h)
{
	node* c = *h;
	node* f = nullptr;
	node* p = nullptr;
	while (c != nullptr)
	{
		f = c->next;
		c->next = p;
		p = c;
		c = f;
	}
	*h = p;
}
int main()
{
	node* man = nullptr;
	// Inserting nodes in a singly linked list
	for (int i = 0; i < 5; i++)
	{
		insert(&man, i*i);
	}
	// printing a linked list
	cout << "\nOriginal List : ";
	print(man);
	reverse(&man);
	cout << "\nModified List : ";
	print(man);
	remove(man);
	man = nullptr;
	return 0;
}