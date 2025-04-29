#include<iostream>
using namespace std;
// struct treenode
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode*  right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
// Class Solution
class solution
{
public:
	bool isSymmetric(TreeNode* root)
	{
		if (root == NULL)
			return true;
		return isMirror(root->left, root->right);
	}
	bool isMirror(TreeNode* left, TreeNode* right)
	{
		if (left == NULL && right == NULL)
			return true;
		else if (left == NULL || right == NULL)
			return false;
		return (left->val == right->val) && isMirror(left->right, right->left) && isMirror(left->left, right->right);
	}
};
int main()
{
	// Create a sample binaryt tree
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(3);
	solution solutio;
	bool result = solutio.isSymmetric(root);
	cout << "\nIs symmetric : " << (result ? "true" : "false") << "\n";
	return 0;
}