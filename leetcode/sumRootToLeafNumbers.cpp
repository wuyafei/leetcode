#include"util.h"
#include<stack>
using namespace std;

/*
	Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
*/

int sumNumbers(TreeNode *root) {
	int sum = 0;
	stack<pair<TreeNode*, int> > s;
	s.push(make_pair(root, root->val));
	while (!s.empty()){
		pair<TreeNode*, int> p = s.top();
		s.pop();
		if (p.first->left == NULL && p.first->right == NULL)
			sum += p.second;
		if(p.first->left != NULL)
			s.push(make_pair(p.first->left, p.second * 10 + p.first->left->val));
		if(p.first->right!=NULL)
			s.push(make_pair(p.first->right, p.second * 10 + p.first->right->val));
	}
	return sum;
}