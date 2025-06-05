#include<iostream>
using namespace std;
// node struct 
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
		node* temp; nullptr;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}
// Function to calculate length of a linked list
int len(node* head)
{
	int l = 0;
	while (head != nullptr)
	{
		l++;
		head = head->next;
	}
	return l;
}
// Function to rotate right
node* right(node* head, int k)
{
	int le = len(head);
	node* a = head;
	while (head->next != nullptr)
	{
		head = head->next;
	}
	head->next = a;
	node* b = head;
	node* c = nullptr;
	for (int i = 1; i < le - 1; i++)
	{
		b = b->next;
	}
	node* ptr = b->next;
	b->next = nullptr;
	return ptr;
}
int main()
{
	node* h = nullptr;
	// Inserting  nodes
	insert(&h, 20);
	insert(&h, 21);
	insert(&h, 22);
	insert(&h, 23);
	insert(&h, 24);
	insert(&h, 25);
	insert(&h, 26);
	cout << "\nLinked list   : ";
	print(h);
	h = right(h, 2);
	cout << "\nModified list : ";
	print(h);
	remove(h);
	h = nullptr;
	return 0;
}