/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        struct ListNode *t,*q,*p;
        t=p=q=head;
        int l=0;
        while(t->next!=NULL){
            t=t->next;
            l++;
        }
        
        if(l%2){
            while(p!=NULL && p->next!=NULL){
                q=q->next;
                p=p->next;
                p=p->next;
            };
        }
        else {
            while (p!=NULL && p->next!=NULL && ((p->next)->next) != NULL){
                q=q->next;
                p=p->next;
                p=p->next;
            }
        }
        return q;
    }
};

//2 pass O(n) solution