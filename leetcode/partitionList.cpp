#include"util.h"
using namespace std;

/*
	Given a linked list and a value x, partition it such that all nodes less than x come before
	nodes greater than or equal to x.
	You should preserve the original relative order of the nodes in each of the two partitions.
*/
ListNode *partition(ListNode *head, int x) {
	ListNode hh(0);
	hh.next = head;
	ListNode* pi = &hh;
	ListNode* pj = &hh;
	while (pi->next != NULL && pj->next != NULL){
		if (pj->next->val < x){
			//pi = pi->next;
			if (pj != pi){
				ListNode* tmp_j = pj->next;
				pj->next = tmp_j->next;
				ListNode* tmp_i = pi->next;
				pi->next = tmp_j;
				tmp_j->next = tmp_i;
			}
			else
				pj = pj->next;
			pi = pi->next;
		}
		else
			pj = pj->next;
	}
	return hh.next;
}