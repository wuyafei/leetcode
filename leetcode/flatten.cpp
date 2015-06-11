#include"util.h"
using namespace std;
/*
Given a binary tree, flatten it to a linked list in-place.
*/
TreeNode* flatten_r(TreeNode* node){
	if (!node)
		return NULL;
	TreeNode* l = flatten_r(node->left);
	TreeNode* r = flatten_r(node->right);
	TreeNode* n = node;
	n->left = NULL;
	n->right = l;
	while (n->right)
		n = n->right;
	n->right = r;
	return node;
}

void flatten(TreeNode *root){
	flatten_r(root);
}