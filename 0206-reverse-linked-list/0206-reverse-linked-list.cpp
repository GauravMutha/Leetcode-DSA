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
//#3 Reversal by addresses of nodes - recursive
class Solution {
public:
    ListNode* helper(ListNode* curr,ListNode* &head){
        if(curr==nullptr) return nullptr;
        auto retNode=helper(curr->next,head);
        if(!retNode) head=curr;
        else {
            retNode->next=curr;
            curr->next=nullptr;
        }
        return curr;
    }
    ListNode* reverseList(ListNode* head) {
        auto curr=head;
        helper(curr,head);
        return head;
    }
};