#include"util.h"
#include<vector>
#include<stack>
using namespace std;

/*
	Given a binary tree, return the postorder traversal of its nodes' values.
*/
vector<int> postorderTraversal(TreeNode *root) {
	vector<int> v;
	if (root == NULL)
		return v;
	stack<TreeNode*> stk;
	stk.push(root);
	while (!stk.empty()){
		TreeNode* tmp = stk.top();
		stk.pop();
		v.push_back(tmp->val);
		if (tmp->left != NULL){
			stk.push(tmp->left);
		}
		if (tmp->right != NULL){
			stk.push(tmp->right);
		}
	}
	reverse(v.begin(), v.end());
	return v;
}