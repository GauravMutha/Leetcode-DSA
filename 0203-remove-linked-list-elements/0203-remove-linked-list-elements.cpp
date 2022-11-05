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
    ListNode* removeElements(ListNode* head, int x) {
        struct ListNode *start , *start_head;
        start=new ListNode(-1);
        start_head=start;
        while(head){
            while(head && head->val==x) head=head->next;
            start->next=head;
            start=start->next;
            if(head) head= head->next;
        }
        return start_head->next;
    }
};
//dummy node
//single pointer approach