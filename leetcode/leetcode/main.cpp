#include "leetcode.h"
#include<iostream>
#include<time.h>
#include"util.h"

int main(){
	ListNode p1(1);
	ListNode p2(2);
	ListNode p3(3);
	ListNode p4(4);
	ListNode p5(5);
	ListNode p6(6);
	p2.next = &p3;
	p3.next = &p4;
	p4.next = &p5;
	p5.next = &p6;
	p1.next = &p5;
	
	int t = clock();
	ListNode* isn = getIntersectionNode(&p1, &p2);
	cout << isn->val << endl;
	t = clock() - t;
	cout << "time=" << t << endl;
	getchar();
	return 0;
}