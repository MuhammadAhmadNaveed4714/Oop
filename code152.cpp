#include<iostream>
using namespace std;
// Struct node
struct node
{
	int data;
	node* left;
	node* right;
};
// Function to create a new binary tree
node* create(int data)
{
	node* newnode = new node();
	newnode->data = data;
	newnode->left = nullptr;
	newnode->right = nullptr;
	return newnode;
}
// Function to insert a node in a binary tree
node* insert(node* root, int data)
{
	if (root == nullptr)
	{
		root = create(data);
		return root;
	}
	if (data < root->data)
	{
		root->left = insert(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = insert(root->right, data);
	}
	return root;
}
// Function to perform inorder traversal
void inorder(node* root)
{
	if (root == nullptr)
	{
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
// Function to delete a binary tree
void remove(node* root)
{
	if (root == nullptr)
	{
		return;
	}
	remove(root->left);
	remove(root->right);
	delete root;
}
int main()
{
	node* root = nullptr;
	// inserting nodes in a binary tree
	root = insert(root, 8);
	cout << root << "\t";
	root = insert(root, 3);
	cout << root << "\t";
	root = insert(root, 10);
	cout << root << "\t";
	root = insert(root, 1);
	cout << root << "\t";
	root = insert(root, 6);
	cout << root << "\t";
	root = insert(root, 14);
	cout << root << "\t";
	root = insert(root, 4);
	root = insert(root, 7);
	root = insert(root, 13);
	perform inorder traversal of the biary tree
		cout << "\n\t\t\t\t\tInorder traversal : ";
	inorder(root);
	cout << "\n";
	// delete the root in binary tree
	remove(root);
	root = nullptr;
	return 0;
}