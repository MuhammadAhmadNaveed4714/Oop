#include<iostream>
using namespace std;
// Node structure
struct node
{
	int data;
	node* next;
};
// Function to create a node
node* create(int data)
{
	node* newnode = new node();
	newnode->data = data;
	newnode->next = nullptr;
	return newnode;
}
// Function to insert a node at the end of a linked list
void insert(node** head, int data)
{
	node* newnode = create(data);
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
// Function to remove the linked list
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
// Function to rotate list by k number of positions to the right
node* rotateright(node* head, int k)
{
	if (head == nullptr || head->next == nullptr || k == 0)
	{
		return head;
	}
	// Calculate length of the list
	node* temp = head;
	int length = 1;
	while (temp->next != nullptr)
	{
		temp = temp->next;
		length++;
	}
	// Connect last node to the head to form a circular list
	temp->next = head;
	// calculate the new tail node's position
	k = k % length;
	int nposition = length - k - 1;
	// Find the new tail node
	node* newtail = head;
	for (int i = 0; i < nposition; i++)
	{
		newtail = newtail->next;
	}
	// Find the new head node
	node* newhead = newtail->next;
	// Break the circular list at the new tail node
	newtail->next = nullptr;
	return newhead;
}
int main()
{
	node* head = nullptr;
    // Create a sample linked list
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);
	cout << "\nOriginal List : ";
	print(head);
	int k = 2;
	head = rotateright(head, k);
	cout << "\nRotated List : ";
	print(head);
	remove(head);
	head = nullptr;
	return 0;
}