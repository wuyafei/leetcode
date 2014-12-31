#include"util.h"
#include<queue>
using namespace std;


TreeNode* creatBST(int n){
	queue<TreeNode*> q;
	TreeNode* root = new TreeNode(0);
	n--;
	q.push(root);
	while (!q.empty() && n!=0){
		TreeNode* tn = q.front();
		q.pop();
		if (n != 0){
			tn->left = new TreeNode(0);
			n--;
			q.push(tn->left);
		}
		if (n != 0){
			tn->right = new TreeNode(0);
			n--;
			q.push(tn->right);
		}
	}
	return root;
}

ListNode* inorderTraversal(TreeNode* root, ListNode* head){
	if (!root || !head)
		return NULL;
	ListNode* ln = head;
	if (root->left){
		ln=inorderTraversal(root->left,head);
	}
	root->val = ln->val;
	if (root->right){
		return inorderTraversal(root->right, ln->next);
	}
	return ln->next;
}


TreeNode* sortedListToBST(ListNode *head) {
	int length = 0;
	ListNode* p = head;
	while (p){
		p = p->next;
		length++;
	}
	TreeNode* root = creatBST(length);
	inorderTraversal(root, head);
	return root;
}