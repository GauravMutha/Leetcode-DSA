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
    ListNode *detectCycle(ListNode *head) {
        struct ListNode* fast=head,*slow=head;
        if(head==NULL) return NULL;
        do{
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }while(fast && slow && fast!=slow);
        while(fast && (head != fast) ){
            head=head->next;
            fast=fast->next;
        }
        return fast;
    }
};

//2 pointers with no extra space