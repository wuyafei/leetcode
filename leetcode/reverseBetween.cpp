/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode pseudoHead=ListNode(0);
        pseudoHead.next=head;
        int l=n-m+1;
        ListNode* p1=&pseudoHead;
        while(--m > 0)
            p1=p1->next;
        ListNode* p2=p1->next;
        ListNode* pre=p1;
        ListNode* p=pre->next;
        ListNode* post;
        for(int i=0;i<l;i++){
            post=p->next;
            p->next=pre;
            pre=p;
            p=post;
        }
        p1->next=pre;
        p2->next=p;
        return pseudoHead.next;
    }
};