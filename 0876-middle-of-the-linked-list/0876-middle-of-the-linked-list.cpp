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
        if(head==NULL || head->next==NULL) return head;
        auto dummy=new ListNode(-1) , p=dummy,q=dummy;
        dummy->next=head;
        
        while(p){
            p=p->next;
            if(p) p=p->next;
            q=q->next;
        }
        
        return q;
    }
};