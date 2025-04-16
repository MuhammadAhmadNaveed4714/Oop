#include<iostream>
using namespace std;
//Node structure for a singly linked list
struct node
{
	int data;
	node* next;
};
//Function to insert a new node at the end of the linked list
void insertNode(node** head, int value)
{
	node* newnode = new node();
	newnode->data = value;
	newnode->next = nullptr;
	if (*head == nullptr)
	{
		*head = newnode;
	}
	else
	{
		node* temp = *head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
}
//Function to find the middle of the even linked list
void findMiddleOdd(node* head)
{
	if (head == nullptr)
	{
		cout << "\nList is empty.\n";
		return;
	}
	node* slow = head;
	node* fast = head;
	node* prev = nullptr;
	while (fast != nullptr && fast->next != nullptr)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << "\n\n\t\t\t\t\tOdd Middle element is " << prev->data << ".\n";
}
//Function to find the middle of the odd linked list
void findMiddleEven(node* head)
{
	if (head == nullptr)
	{
		cout << "\nList is empty.\n";
		return;
	}
	node* slow = head;
	node* fast = head;
	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << "\n\n\t\t\t\t\tEven Middle element is " << slow->data << ".\n";
}
//Function to print the linked list
void printlist(node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}
//Function to remove the linked list
void remove(node* head)
{
	while (head != nullptr)
	{
		node* temp = head;
		head = head->next;
		delete temp;
	}
}
int main()
{
	node* head = nullptr;
	//Inserting nodes into the linked list
	insertNode(&head, 1);
	insertNode(&head, 2);
	insertNode(&head, 3);
	insertNode(&head, 4);
	insertNode(&head, 5);
	insertNode(&head, 6);
	insertNode(&head, 7);
	cout << "\n\n\t\t\t\t\tLinked list : ";
	printlist(head);
	findMiddleEven(head);
	findMiddleOdd(head);
	remove(head);
	head = nullptr;
	return 0;
}