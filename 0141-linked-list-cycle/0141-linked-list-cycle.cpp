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
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        auto fast=head;
        auto slow=head;
        
        do{ 
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
            
        }
        while(fast && slow && fast!=slow);
        if(fast==NULL) return false;
        return true;
    }
};