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
//Iteratively
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val1=0,val2=0,val3,carry=0;
        struct ListNode *ptr1=l1 , *ptr2=l2 , dummy(-1) , *pre;
        pre=&dummy;
        
        while(ptr1 || ptr2 || carry){
            val1=0,val2=0;
            if(ptr1) val1=ptr1->val, ptr1=ptr1->next;
            if(ptr2) val2=ptr2->val, ptr2=ptr2->next;
            
            pre->next=new ListNode((val1+val2+carry)%10);
            pre=pre->next;
            carry=(val1+val2+carry)/10;
        }
        return dummy.next;
    }
};