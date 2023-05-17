/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Calculating Differences
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        
        auto p=headA , q=headB;
        while(p->next && q->next)
            p=p->next , q=q->next;
        
        int diff=0;
        if(p->next==NULL){
            while(q->next) q=q->next , diff++;
            if(q!=p) return NULL; //no connection , two separate LL
            p=headA , q=headB;
            while(diff--) q=q->next;
            while(p!=q) p=p->next , q=q->next;
        }
        else if(q->next==NULL){
            while(p->next) p=p->next , diff++;
            if(q!=p) return NULL; //no connection , two separate LL
            p=headA , q=headB;
            while(diff--) p=p->next;
            while(p!=q) p=p->next , q=q->next;
        }
        
        
        return p;
    }
};