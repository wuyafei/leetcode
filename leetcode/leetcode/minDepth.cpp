#include"util.h"
using namespace std;

int inline minimum(int a, int b){
	return a < b ? a : b;
}
int minDepth(TreeNode *root){
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else if (root->left == NULL)
		return 1 + minDepth(root->right);
	else if (root->right == NULL)
		return 1 + minDepth(root->left);
	else
		return 1 + minimum(minDepth(root->left), minDepth(root->right));
}




































