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
// Function to return a length
int length(node* head)
{
	int length = 0;
	while (head != nullptr)
	{
		head = head->next;
		length++;
	}
	return length;
}
//// Function to rotate a node to its right by specified number of positions
node* right(node* head, int k)
{
	int len = length(head);
	int c = 1;
	node* temp = head;
	while (c < len - k)
	{
		temp = temp->next;
		c++;
	}
	node* ntr = temp->next;
	node* ptr = ntr;
	temp->next = nullptr;
	while (ntr->next != nullptr)
	{
		ntr = ntr->next;
	}
	ntr->next = head;
	return ptr;
}
// Function to rotate a node to its left by specified number of positions
node* left(node* head, int k)
{
	int len = length(head);
	int c = 1;
	node* temp = head;
	node* ptr = head;
	while (c < len - k - 1)
	{
		ptr = ptr->next;
		c++;
	}
	node* ntr = ptr->next;
	node* str = ntr;
	ptr->next = nullptr;
	while (str->next != nullptr)
	{
		str = str->next;
	}
	str->next = head;
	return ntr;
}
int main()
{
	node* head = nullptr;
	node* tail = nullptr;
	// Inserting nodes in the head
	insert(&head, 10);
	insert(&head, 20);
	insert(&head, 30);
	insert(&head, 40);
	insert(&head, 50);
	// Inserting nodes in the tail
	insert(&tail, 10);
	insert(&tail, 20);
	insert(&tail, 30);
	insert(&tail, 40);
	insert(&tail, 50);
	// printing linked list
	cout << "\nReal  List : ";
	print(tail);
	// rotating right
	head = right(head, 2);
	cout << "\nRight List : ";
	print(head);
	// rotating left
	tail = left(tail, 2);
	cout << "\nLeft  List : ";
	print(tail);
	remove(head);
	head = nullptr;
	remove(tail);
	tail = nullptr;
	return 0;
}