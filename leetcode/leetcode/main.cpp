#include "leetcode.h"
#include<iostream>
#include<time.h>
#include"util.h"

int main(){
	ListNode p4(4);
	ListNode p3(3);
	ListNode p2(2);
	ListNode p1(1);
	p1.next = &p2;
	p2.next = &p3;
	p3.next = &p4;
	ListNode* h = &p1;
	while (h){
		cout << h->val << endl;
		h = h->next;
	}
	h = &p1;
	int t = clock();
	reorderList(h);
	t = clock() - t;
	cout << "time=" << t << endl;
	
	while (h){
		cout << h->val << endl;
		h = h->next;
	}
	getchar();
	return 0;
}