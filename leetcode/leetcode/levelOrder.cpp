#include"util.h"
#include<vector>
#include<queue>
using namespace std;
/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
*/
vector<vector<int> > levelOrder(TreeNode* root){
	vector<vector<int> > rslt;
	vector<int> vct;
	if (!root)
		return rslt;
	int cnt;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()){
		cnt = q.size();
		while (cnt > 0){
			TreeNode* node = q.front();
			q.pop();
			vct.push_back(node->val);
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
			cnt--;
		}
		rslt.push_back(vct);
		vct.clear();
	}
	return rslt;
}