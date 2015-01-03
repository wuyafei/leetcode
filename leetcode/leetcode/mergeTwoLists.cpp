#include"util.h"
using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
	if (!l1)
		return l2;
	if (!l2)
		return l1;
	ListNode *p1, *p2;
	if (l1->val < l2->val){
		p1 = l1;
		p2 = l2;
	}
	else{
		p2 = l1;
		p1 = l2;
	}
	ListNode* head = p1;
	while (p1->next && p2){
		if (p1->next->val < p2->val){
			p1 = p1->next;
		}
		else{
			ListNode* tmp1 = p1->next;
			ListNode* tmp2 = p2->next;
			p1->next = p2;
			p2->next = tmp1;
			p2 = tmp2; 
			p1 = p1->next;
		}
	}
	if (!p1->next){
		p1->next = p2;
	}
	return head;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode dummy(0);
	ListNode *tail = &dummy;

	while (l1 && l2) {
		if (l1->val < l2->val) {
			tail->next = l1;
			l1 = l1->next;
		}
		else {
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}

	tail->next = l1 ? l1 : l2;
	return dummy.next;
}