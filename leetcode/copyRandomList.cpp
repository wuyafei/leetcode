/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode* p=head;
        RandomListNode* cpHead = new RandomListNode(p->label);
        RandomListNode* q=cpHead;
        q->random=p->random;
        unordered_map<RandomListNode*,RandomListNode*> map;
        map[p]=q;
        p=p->next;
        while(p){
            RandomListNode *tmp=new RandomListNode(p->label);
            tmp->random=p->random;
            q->next=tmp;
            q=q->next;
            map[p]=q;
            p=p->next;
        }
        q=cpHead;
        while(q){
            if(q->random!=NULL){
                q->random=map[q->random];
            }
            q=q->next;
        }
        return cpHead;
        
    }
};