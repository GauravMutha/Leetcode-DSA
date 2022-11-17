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
   void reverse(ListNode** head) {
       struct ListNode *curr=*head,*pre=NULL,*front;
       while(curr){
           front=curr->next;
           curr->next=pre;
           pre=curr;
           curr=front;
       }
       *head=pre;
    }    
    
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        struct ListNode *f=head,*s=head;
        while(f && f->next){
            f=f->next->next;
            s=s->next;
        }
        if(f) s=s->next; //odd length
        reverse(&s);
        for(auto p =head;s!=NULL;s=s->next,p=p->next){
            if(p->val!=s->val) return false;
        }
        return true;
    }
};
//TC-->O(n) + 3 pass;
//SC-->O(1)