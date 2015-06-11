#include"util.h"
using namespace std;

/*
Given a linked list, determine if it has a cycle in it.
*/

//faster runner and slower runner
bool hasCycle(ListNode* head){
	if (!head)
		return false;
	ListNode* p1 = head;
	ListNode* p2 = head;
	do{
		p1 = p1->next;
		p2 = p2->next;
		if (!p1 || !p2)
			return false;
		p2 = p2->next;
		if (!p2)
			return false;
	} while (p1 != p2);
	return true;
}