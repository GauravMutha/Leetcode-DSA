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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        struct ListNode *p=head,*q=head->next,*knot=head->next;    
        while(q && q->next){
            p->next=q->next;
            q->next=p->next->next;
            q=q->next;
            p=p->next;
        }
        p->next=knot;
        return head;
        
    }
};

//iterative