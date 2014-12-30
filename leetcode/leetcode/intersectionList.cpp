#include"util.h"
using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (!headA || !headB)
		return NULL;
	ListNode* pa = headA;
	ListNode* pb = headB;
	while (pa && pb){
		if (pa == pb)
			return pa;
		pa = pa->next;
		pb = pb->next;
		if (!pa && !pb)
			return NULL;
		if (!pa)
			pa = headB;
		if (!pb)
			pb = headA;
	}
}