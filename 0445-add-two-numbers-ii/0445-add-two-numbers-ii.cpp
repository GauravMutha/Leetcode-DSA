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
        stack<struct ListNode*>st1 ,st2;
        struct ListNode *l3=NULL , *p=l1,*q=l2 , *dig1,*dig2;
        while(p || q){
            if(p) st1.push(p), p=p->next;
            if(q) st2.push(q), q=q->next;
        }
        //imported from question 2.Add two numbers 
        bool flag1=(st1.size()>=st2.size());
        l3=(flag1) ? l1 :l2;
        int val1=0 , val2=0 , val3=0,carry=0;
        while(!st1.empty() || !st2.empty() || carry){
            val1=0 , val2=0;
            if(!st1.empty()) val1=st1.top()->val;
            if(!st2.empty()) val2=st2.top()->val;
            val3=( (val1+val2 + carry) <10 ? val1+val2+carry : (val1+val2+carry)%10 ); 
            
            if(st1.empty() && st2.empty()){
                struct ListNode* temp=new ListNode(val3);
                temp->next=l3;
                l3=temp;
            }
            else{
               if(flag1) st1.top()->val=val3;
               else st2.top()->val=val3;
            }
            if(!st1.empty()) st1.pop();
            if(!st2.empty()) st2.pop();
            carry=(val1+val2+carry)/10;
        }
        return l3;
    }
};
//Without Reversing -- > Uses 2 stack
//2 pass
//SC-->O(n)
//TC--> O(n)
