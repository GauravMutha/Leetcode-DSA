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
        if(head==NULL || head->next==NULL) return false;
        struct ListNode *fast =head , *slow=fast;
        do{
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }while(slow && fast && slow != fast);
        return (fast==slow);
    }
};
//Two pointers

//SC -> O(1) TC O(N)