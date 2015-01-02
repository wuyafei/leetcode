#include"util.h"
#include<queue>
using namespace std;

/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

int inline minimum(int a, int b){
	return a < b ? a : b;
}
int minDepth_recursive(TreeNode *root){
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else if (root->left == NULL)
		return 1 + minDepth_recursive(root->right);
	else if (root->right == NULL)
		return 1 + minDepth_recursive(root->left);
	else
		return 1 + minimum(minDepth_recursive(root->left), minDepth_recursive(root->right));
}

//level order tranversal
int minDepth(TreeNode* root){
	if (!root)
		return 0;
	queue<TreeNode*> q;
	root->val = 1;
	q.push(root);
	while (!q.empty()){
		TreeNode* tn = q.front();
		q.pop();
		if (!tn->left && !tn->right)
			return tn->val;
		if (tn->right){
			tn->right->val = tn->val + 1;
			q.push(tn->right);
		}
		if (tn->left){
			tn->left->val = tn->val + 1;
			q.push(tn->left);
		}
	}
}




































