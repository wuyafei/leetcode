#include"util.h"
using namespace std;
/*
	Sort a linked list using insertion sort.
*/
ListNode *insertionSortList(ListNode *head) {
	if (head == NULL)
		return NULL;
	ListNode* virtualHead = new ListNode(0);
	virtualHead->next = head;
	ListNode* p = head;
	ListNode* pn = p->next;
	while (pn != NULL){
		int x = pn->val;
		ListNode* hp = virtualHead;
		ListNode* h = hp->next;
		while (h != pn){
			if (h->val > x){
				hp->next = pn;
				p->next = pn->next;
				pn->next = h;
				break;
			}
			else{
				h = h->next;
				hp = hp->next;
			}
		}
		if (h == pn){
			p = p->next;
			pn = pn->next;
		}
		else{
			pn = p->next;
		}
			
	}
	return virtualHead->next;
}