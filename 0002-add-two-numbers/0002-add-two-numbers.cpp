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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *ptr1=l1 , *ptr2=l2 , dummy(-1),*curr;
        curr=&dummy;
        int val1=0 , val2=0 , val3=0,carry=0;
        while(ptr1 || ptr2 || carry){
            val1=0 , val2=0;
            if(ptr1) val1=ptr1->val , ptr1=ptr1->next;
            if(ptr2) val2=ptr2->val , ptr2=ptr2->next;
            val3=( (val1+val2 + carry) <10 ? val1+val2+carry : (val1+val2+carry)%10 ); 
            curr->next=new ListNode(val3);
            curr=curr->next;
            carry=(val1+val2+carry)/10;
        }
        return dummy.next;
    }
};