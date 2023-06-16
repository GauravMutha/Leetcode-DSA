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
    void reverse(ListNode* &head) {
       auto curr=head;
        ListNode *pre=NULL,*front=NULL;
       while(curr){
           front=curr->next;
           curr->next=pre;
           pre=curr;
           curr=front;
       }
       head=pre;
    } 
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        stack<int>st;
        ListNode *f=head, *s=head;
        
        while(f && f->next) s=s->next ,f=f->next->next;
        if(f) s=s->next;
        reverse(s);
        
        for(auto p=head;s;s=s->next,p=p->next){
            if(s->val!=p->val) return false;
        }
        
        return true;
    }
};