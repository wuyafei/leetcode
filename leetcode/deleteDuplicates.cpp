#include"util.h"
using namespace std;

ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
            return NULL;
        ListNode phead(0);
        phead.next=head;
        ListNode* h=head;
        ListNode* p=head;
        while(p){
            if(p->val > h->val){
                h->next=p;
                h=h->next;
            }
            p=p->next;
        }
        h->next=NULL;
        return phead.next;
}

