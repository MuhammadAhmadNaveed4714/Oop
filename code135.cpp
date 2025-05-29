#include <iostream>
using namespace std;
// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
// Fu ction to find mirror of a binary tree
void mirrorTree(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    // Recursively mirror left and right subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
    // Swap left and right subtrees
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}
// Function to delete a binary tree
void deleteTree(Node* root) {
    if (root == nullptr) return;

    deleteTree(root->left);  // Delete the left subtree
    deleteTree(root->right);  // Delete the right subtree
    delete root;  // Delete the current node
}
// Function to print the inorder traversal of the binary tree
void printInorder(Node* root) {
    if (root != nullptr) {
        printInorder(root->left);  // Visit the left subtree
        cout << root->data << " ";  // Visit the current node
        printInorder(root->right);  // Visit the right subtree
    }
}
int main() {
    // Create a sample binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    cout << "\nBinary tree created. Inorder traversal: ";
    printInorder(root);
    cout << endl;
    // Mirror tree
    mirrorTree(root);
    cout << "\nMirror tree created. Inorder traversal: ";
    printInorder(root);
    cout << "\n";
    // Delete the binary tree
    deleteTree(root);
    root = nullptr;  // Set the root to nullptr to prevent dangling pointer
    cout << "\nBinary tree deleted." << endl;
    // Attempting to print the inorder traversal after deletion will result in undefined behavior
    // To verify deletion, we can check if the root is nullptr
    if (root == nullptr) {
        cout << "\nRoot is nullptr, tree is deleted." << endl;
        cout << "\nI have made it by my own.\n";
    }
    return 0;
}