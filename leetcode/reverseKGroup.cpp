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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1) return head;
        int len=lenOfList(head);
        int t=len/k;
        if(t<1) return head;
        ListNode pseudoHead(0);
        pseudoHead.next=head;
        ListNode* g_pre=&pseudoHead;
        ListNode* pre=head;
        ListNode* p=head->next;
        ListNode* post;
        for(int i=0;i<t;i++){
            for(int j=0;j<k-1;j++){
                post=p->next;
                p->next=pre;
                pre=p;
                p=post;
            }
            ListNode* tmp=g_pre->next;
            tmp->next=p;
            g_pre->next=pre;
            g_pre=tmp;
            if(p){
                pre=p;
                p=pre->next;
            }
        }
        return pseudoHead.next;
    }
private:
    int lenOfList(ListNode* head){
        int cnt=0;
        ListNode* p=head;
        while(p){
            cnt++;
            p=p->next;
        }
        return cnt;
    }
};