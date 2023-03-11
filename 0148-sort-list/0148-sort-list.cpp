// *
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };

class Solution {
public:
    ListNode* merge(ListNode* left , ListNode* right){
        auto dummy=new ListNode(-1);
        auto temp=dummy;
        while(left && right){
            if(left->val < right->val){
                temp->next=left;
                temp=left;
                left=left->next;
                temp->next=NULL;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
                temp->next=NULL;
            }
        }
        if(left==NULL) temp->next=right;
        else if(right==NULL) temp->next=left;
            
        return dummy->next;
    }
    ListNode* findMid(ListNode* head){
        auto slow=head, fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        //break
        auto left=head;
        auto mid=findMid(head);
        auto right=mid->next;
        mid->next=NULL;
        
        //merge above two halves
        left=sortList(left);
        right=sortList(right);
        
        //merge the sorted halves
        auto result=merge(left,right);
        
        return result;
    }
};