#include"util.h"
#include<vector>
using namespace std;

/*
	Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
*/
vector<TreeNode*> genTree(int start, int end){
	vector<TreeNode*> *v = new vector<TreeNode*>();
	if (start > end){
		(*v).push_back(NULL);
		return *v;
	}
	if (start == end){
		(*v).push_back(new TreeNode(start));
		return *v;
	}
	vector<TreeNode*> left, right;
	for (int i = start; i <= end; i++){
		left = genTree(start, i - 1);
		right = genTree(i + 1, end);
		for (vector<TreeNode*>::iterator itrl = left.begin(); itrl != left.end(); itrl++){
			for (vector<TreeNode*>::iterator itrr = right.begin(); itrr != right.end(); itrr++){
				TreeNode *tn = new TreeNode(i);
				(*tn).left = (*itrl);
				(*tn).right = (*itrr);
			}
		}
	}
	return *v;
}


vector<TreeNode*> generateTrees(int n) {
	return genTree(0, n - 1);
}

