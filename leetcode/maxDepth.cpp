#include"util.h"
using namespace std;

int heightOfTree(TreeNode* node){
	if (!node)
		return 0;
	else return 1 + max(heightOfTree(node->left), heightOfTree(node->right));
}

int maxDepth(TreeNode* root){
	return heightOfTree(root);
}
