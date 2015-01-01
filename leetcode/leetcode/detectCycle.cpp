#include"util.h"
using namespace std;

ListNode* detectCycle(ListNode* head){
	if (!head)
		return NULL;
	ListNode* p1 = head;
	ListNode* p2 = head;
	do{
		p1 = p1->next;
		p2 = p2->next;
		if (!p1 || !p2)
			return NULL;
		p2 = p2->next;
		if (!p2)
			return NULL;
	} while (p1 != p2);
	ListNode* p3 = head;
	while (p1 != p3){
		p1 = p1->next;
		p3 = p3->next;
	}
	return p1;
}