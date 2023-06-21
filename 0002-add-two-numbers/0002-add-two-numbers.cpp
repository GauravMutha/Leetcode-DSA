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
//Recursively
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2 , int carry=0) {
        if(l1==NULL && l2==NULL && carry==0) return NULL;
        int val1=0,val2=0;
        if(l1) val1=l1->val;
        if(l2) val2=l2->val;
        
        auto curr=new ListNode((val1+val2+carry)%10);
        carry=(val1+val2+carry)/10;
        curr->next= addTwoNumbers((l1)? l1->next :NULL,(l2)? l2->next :NULL,carry);
        
        return curr;
    }
};