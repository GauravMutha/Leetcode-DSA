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
    
    int pairSum(ListNode* head) {
        struct ListNode *fast=head , *slow=head,*p,*q;
        int ans=INT_MIN,len=0;
        while(fast && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        reverse(&slow);
        p=slow , q=head;
        while(p && q){
            ans=max(ans,p->val+q->val);
            p=p->next;
            q=q->next;
        }
        return ans;
    }
};
//Two pointers
//TC-->O(n)  (3 pass but only 3*n/2 traversal)
//SC-->O(1)
