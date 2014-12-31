#include "leetcode.h"
#include<iostream>
#include<time.h>
#include"util.h"

void inorder(TreeNode* root){
	if (root->left)
		inorder(root->left);
	cout << root->val << endl;
	if (root->right)
		inorder(root->right);
}

int main(){
	ListNode p1(1);
	ListNode p2(2);
	ListNode p3(3);
	ListNode p4(4);
	//ListNode p5(5);
	p1.next = &p2;
	p2.next = &p3;
	p3.next = &p4;
	//p4.next = &p5;

	int t = clock();
	TreeNode* tn = sortedListToBST(&p1);
	inorder(tn);
	t = clock() - t;
	cout << "time=" << t << endl;
	getchar();
	return 0;
}