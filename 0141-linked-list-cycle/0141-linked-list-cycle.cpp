/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//without using extra space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto dummy=new ListNode(-1),p=dummy,q=dummy;
        dummy->next=head;
        while(p){
            p=p->next;
            if(p) p=p->next;
            q=q->next;
            if((p==q ) && p && q) return true;
        }
        return false;
    }
};