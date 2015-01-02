#include"util.h"
#include<vector>
#include<stack>
using namespace std;

vector<int> inorderTraversal(TreeNode *root){
	stack<TreeNode*> stk;
	stk.push(root);
	vector<int> vct;
	if (!root)
		return vct;
	while (!stk.empty()){
		TreeNode* tn = stk.top();
		stk.pop();
		if (tn){
			stk.push(tn->right);
			stk.push(tn);
			stk.push(tn->left);
		}
		else{
			if (!stk.empty()){
				tn = stk.top();
				stk.pop();
				vct.push_back(tn->val);
			}
		}
	}
	return vct;
}