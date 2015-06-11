#include"util.h"
#include<vector>
#include<stack>
using namespace std;

//this solution get the time limit exceed error
//vector<vector<int> > pathSum2(TreeNode* root, int sum){
//	vector<vector<int> > rslt;
//	if (!root)
//		return rslt;
//	stack<pair<TreeNode*, int> > stk;
//	vector<int> vec;
//	stk.push(make_pair(root, sum));
//	while (!stk.empty()){
//		pair<TreeNode*, int> p = stk.top();
//		stk.pop();
//		vec.push_back(p.second);
//		if (p.second == p.first->val && !p.first->left && !p.first->right){
//			rslt.push_back(vec);
//			vec.pop_back();
//		}
//		if (p.first->right){
//			stk.push(make_pair(p.first->right, p.second - p.first->val));
//		}
//		if (p.first->left){
//			stk.push(make_pair(p.first->left, p.second - p.first->val));
//		}
//	}
//	return rslt;
//}
void pathDown(TreeNode* node, int target, vector<vector<int> > &rslt, vector<int> vec){
	if (!node)
		return;
	vec.push_back(node->val);
	if (node->val == target && !node->left && !node->right){
		rslt.push_back(vec);
		return;
	}
	pathDown(node->left, target - node->val, rslt, vec);
	pathDown(node->right, target - node->val, rslt, vec);
}

vector<vector<int> > pathSum2(TreeNode* root, int sum){
	vector<vector<int> > rslt;
	vector<int> vec;
	pathDown(root, sum, rslt, vec);
	return rslt;
}

