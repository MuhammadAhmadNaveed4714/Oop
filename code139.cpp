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
// Function to remove a linked list
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
// Function to calculate a length of linked list
int length(node* head)
{
	int len = 0;
	while (head != nullptr)
	{
		head = head->next;
		len++;
	}
	return len;
}
// Function to rotate left in a linked list
node* left(node* head, int k)
{
	int l = length(head);
	node* temp = head;
	node* ptr = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = head;
	int c = 1;
	while (c < l - k )
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
	node* man = nullptr;
	// Inserting nodes in the list
	insert(&man, 10);
	insert(&man, 20);
	insert(&man, 30);
	insert(&man, 40);
	insert(&man, 50);
	// Printing linked list
	cout << "\nOriginal Linked list : ";
	print(man);
	man = left(man, 2);
	// Printing linked list
	cout << "\nModified Linked list : ";
	print(man);
	remove(man);
	man = nullptr;
	return 0;
}