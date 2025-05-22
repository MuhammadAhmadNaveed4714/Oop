#include<iostream>
using namespace std;
// Struct node
struct node
{
	int data;
	node* next;
};
// Function to insert a node in linked list
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
// Function to remove a node in the linked list
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
// Function to calculate length of a linked list
int length(node* head)
{
	int l = 0;
	while (head != nullptr)
	{
		head = head->next;
		l++;
	}
	return l;
}
// Function to rotate right in the linked list
node* right(node* head, int k)
{
	int len = length(head);
	node* temp = head;
	node* ptr = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = head;
	int c = 1;
	while (c < k)
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
	int k = 0;
	cout << "\nEnter value of k : ";
	cin >> k;
	node* man = nullptr;
	// Inserting nodes in the linked list
	insert(&man, 10);
	insert(&man, 20);
	insert(&man, 30);
	insert(&man, 40);
	insert(&man, 50);
	insert(&man, 60);
	insert(&man, 70);
	insert(&man, 80);
	insert(&man, 90);
	insert(&man, 100);
	// Printing of a linked list
	cout << "\nOriginal Linked List : ";
	print(man);
	// rotating linked list to right
	man = right(man, k);
	// Printing of a linked list
	cout << "\nModified Linked List : ";
	print(man);
	// Removal of linked list
	remove(man);
	man = nullptr;
	return 0;
}