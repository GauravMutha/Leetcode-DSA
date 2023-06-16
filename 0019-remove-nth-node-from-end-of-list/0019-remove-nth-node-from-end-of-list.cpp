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
//Purely iterative
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode dummy(-1,head) , *fast, *slow;
        fast=slow=&dummy;
        
        while(n-- && fast) fast=fast->next;
        
        while(fast && fast->next) slow=slow->next , fast=fast->next;
        
        slow->next=slow->next->next;
        
        return dummy.next;
        
    }
};