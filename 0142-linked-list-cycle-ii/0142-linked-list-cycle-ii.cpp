/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Slow and fast pointers method;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        
        auto fast=head, slow=head;
        
        do{
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }while(fast && fast!=slow);
        
        if(fast==NULL) return NULL;
        
        fast=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        
        return fast;
    }
};