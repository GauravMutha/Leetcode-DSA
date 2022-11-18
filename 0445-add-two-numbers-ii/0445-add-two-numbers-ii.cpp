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
        stack<ListNode*>st1 ,st2;
        struct ListNode *l3=NULL;
        while(l1 || l2){
            if(l1) st1.push(l1), l1=l1->next;
            if(l2) st2.push(l2), l2=l2->next;
        }
        //imported from question 2.Add two numbers 
        
        int val1=0 , val2=0 , val3=0,carry=0;
        while(!st1.empty() || !st2.empty() || carry){
            val1=0 , val2=0;
            if(!st1.empty()) val1=st1.top()->val, st1.pop();
            if(!st2.empty()) val2=st2.top()->val , st2.pop();
            val3=( (val1+val2 + carry) <10 ? val1+val2+carry : (val1+val2+carry)%10 ); 
            
            struct ListNode* temp=new ListNode(val3);
            temp->next=l3;
            l3=temp;
            carry=(val1+val2+carry)/10;
        }
        return l3;
    }
};
//Without Reversing -- > Uses 2 stack
//2 pass
//SC-->O(n)
//TC--> O(n)
