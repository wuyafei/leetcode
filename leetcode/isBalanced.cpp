#include"util.h"
using namespace std;

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as
a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

//int treeHeight(TreeNode* node){
//	if (!node)
//		return 0;
//	int l = 0, r = 0;
//	l = treeHeight(node->left);
//	r = treeHeight(node->right);
//	return (l > r ? l : r)+1;
//}
//
//bool isBalanced(TreeNode* root){
//	if (!root)
//		return true;
//	int diff = treeHeight(root->left) - treeHeight(root->right);
//	if (diff > 1 || diff < -1)
//		return false;
//	return isBalanced(root->left) && isBalanced(root->right);
//}
const int UNBALANCED = -1;
int getHeight(TreeNode* node){
	if (!node)
		return 0;
	int l = getHeight(node->left);
	int r = getHeight(node->right);
	if (l == UNBALANCED || r == UNBALANCED || l - r > 1 || l - r < -1)
		return UNBALANCED;
	return (l>r ? l : r) + 1;
}
bool isBalanced(TreeNode* root){
	if (!root)
		return true;
	return getHeight(root) != UNBALANCED;
}
