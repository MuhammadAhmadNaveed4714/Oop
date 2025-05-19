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
// Function to rotate a list to right by k number of positions
node* rotate(node* head, int k)
{
	node* temp = head;
	int length = 1;
	while (temp->next != nullptr)
	{
		temp = temp->next;
		length++;
	}
	node* ptr = head;
	temp->next = head;
	int nnn = length - k - 1;
	for (int i = 0; i < nnn; i++)
	{
		ptr = ptr->next;
	}
	node* ntr = ptr;
	ntr = ntr->next;
	ptr->next = nullptr;
	return ntr;
}
int main()
{
	node* ppp = nullptr;
	insert(&ppp, 1);
	insert(&ppp, 2);
	insert(&ppp, 3);
	insert(&ppp, 4);
	insert(&ppp, 5);
	insert(&ppp, 6);
	insert(&ppp, 7);
	cout << "\nOriginal List : ";
	print(ppp);
	ppp = rotate(ppp,4);
	cout << "\nModified List : ";
	print(ppp);
	remove(ppp);
	ppp = nullptr;
	return 0;
}