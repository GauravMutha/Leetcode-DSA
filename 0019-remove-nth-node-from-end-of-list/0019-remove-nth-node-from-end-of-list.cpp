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
    ListNode* mark=NULL;
    int count=0;
    
    void helper(ListNode* &curr, int n){
        if(curr==NULL) return;
        helper(curr->next,n);
        
        count++;
        if(count==(n+1)) mark=curr;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        helper(head,n);
        if(mark==NULL){
            head=head->next;
        }
        else mark->next=mark->next->next;
        return head;
    }
};