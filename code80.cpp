#include<iostream>
using namespace std;
//Struct node
struct node
{
	int data;
	node* head;
};
//Function of creating a node
node* createNode(int k)
{
	node* cnode = new node;
	if (cnode == nullptr)
	{
		cout << "\nMemory Error.\n";
		return nullptr;
	}
	cnode->data = k;
	cnode->head = nullptr;
	return cnode;
}
//Function to insert a node
void insertNode(node** head, int k)
{
	node* newNode = createNode(k);
	if (*head == nullptr)
	{
		*head = newNode;
		return;
	}
	node* lastNode = *head;
	while (lastNode->head != nullptr)
	{
		lastNode = lastNode->head;
	}
	lastNode->head = newNode;
}
//Function to print a node
void printNode(node* A)
{
	while (A != nullptr)
	{
		cout << A->data << " ";
		A = A->head;
	}
	cout << "\n";
}
//Function to deallocate the allocated memory
void remove(node* A)
{
	while (A != nullptr)
	{
		node* temp = A;
		A = A->head;
		delete temp;
	}
}
int main()
{
	node* ball = nullptr;
	insertNode(&ball, 3);
	insertNode(&ball, 6);
	insertNode(&ball, 9);
	insertNode(&ball, 12);
	insertNode(&ball, 15);
	printNode(ball);
	remove(ball);
	ball = nullptr;
	return 0;
}