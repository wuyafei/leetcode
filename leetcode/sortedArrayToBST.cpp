#include<vector>
#include"util.h"
using namespace std;

TreeNode *toBST(vector<int> &num, int l, int h) {
	if (h < l)
		return NULL;
	int m = (l + h) / 2;
	TreeNode* node = new TreeNode(num[m]);
	node->left = toBST(num, l, m - 1);
	node->right = toBST(num, m + 1, h);
	return node;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
	return toBST(num, 0, num.size() - 1);
}