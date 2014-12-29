#include"util.h"
using namespace std;

ListNode* reverseList(ListNode* head){
	ListNode* p = head;
	ListNode* prev = NULL;
	ListNode* post = NULL;
	while (p){
		post = p->next;
		p->next = prev;
		prev = p;
		p = post;
	}
	return prev;
}
//o(n^2) algorithm
void reorderList_bf(ListNode* head){
	if (head == NULL)
		return;
	ListNode* p = head;
	while (p->next){
		p->next = reverseList(p->next);
		p = p->next;
	}
}

//O(n)algorithm, split the list, and reverse the second half, than add the node in the reversed half to the first half one by one
void reorderList(ListNode* head){
	ListNode* p = head;
	int n = 0;
	while (p){
		n++;
		p = p->next;
	}
	p = head;
	if (n < 3)
		return;
	int m = (n-1) / 2;
	while (m){
		m--;
		p = p->next;
	}
	ListNode* pp = reverseList(p->next);
	p->next=NULL;
	p = pp;
	ListNode* h = head;
	while (p){
		ListNode* tp = p->next;
		ListNode* th = h->next;
		h->next = p;
		p->next = th;
		h = th;
		p = tp;
	}

}