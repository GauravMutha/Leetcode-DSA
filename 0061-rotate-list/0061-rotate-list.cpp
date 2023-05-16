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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0) 
            return head;
        
        int nodes=0;
        
        auto fast=head,slow=head;
        while(fast) fast=fast->next , nodes++;
        k%=nodes;
        if(k==0) return head;
        
        fast=head;
        while(k--) fast=fast->next;
        while(fast->next) fast=fast->next, slow=slow->next;
        
        fast->next=head;
        head=slow->next;
        slow->next=nullptr;
        
        return head;
    }
};