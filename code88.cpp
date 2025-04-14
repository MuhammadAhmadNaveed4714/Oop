#include<iostream>
using namespace std;
//struct node
struct node
{
	int data;
	node* next;
};
//Function to create a node
node* createANode(int A)
{
	node* a = new node{ A };
	a->next = nullptr;
	return a;
}
//Function to insert A node
void insertANode(node** head,int a)
{
	node* newNode = createANode(a);
	if (*head == nullptr)
	{
		*head = newNode;
		return;
	}
	node* lastNode = *head;
	while (lastNode->next != nullptr)
	{
		lastNode = lastNode->next;
	}
	lastNode->next = newNode;
}
//Function to reverse a singly linked list
node* reverse(node* head)
{
	node* prev = nullptr;
	node* current = head;
	node* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}
//Function to delete a node
void remove(node* head)
{
	while (head != nullptr)
	{
		node* temp = head;
		head = head->next;
		delete temp;
	}
}
//Function to print a node
void print(node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
}
int main()
{
	node* head = nullptr;
	insertANode(&head, 1);
	insertANode(&head, 2);
	insertANode(&head, 3);
	insertANode(&head, 4);
	insertANode(&head, 5);
	insertANode(&head, 6);
	insertANode(&head, 7);
	insertANode(&head, 8);
	cout << "\n\n\t\t\t\t\tOriginal Array : ";
	print(head);
	head = reverse(head);
	cout << "\n\n\t\t\t\t\tReversed Array : ";
	print(head);
	cout << "\n\n\n";
	remove(head);
	head = nullptr;
	return 0;
}