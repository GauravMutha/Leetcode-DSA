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
    //imported from question 206.Reverse the linked list submission #2
    ListNode* reverseList(ListNode** head) {
        struct ListNode *p,*q{NULL},*r{NULL};
        p=*head;
        
        while(p!=NULL){
            r=q;
            q=p;
            p=p->next;
            
            q->next=r;
        }
        *head=q;
        return q;
    }    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *head=NULL;
        reverseList(&l1);
        reverseList(&l2);
        
        //imported from question 2.Add two numbers 
        int val1=0 , val2=0 , val3=0,carry=0;
        while(l1 || l2 || carry){
            val1=0 , val2=0;
            if(l1) val1=l1->val , l1=l1->next;
            if(l2) val2=l2->val , l2=l2->next;
            val3=( (val1+val2 + carry) <10 ? val1+val2+carry : (val1+val2+carry)%10 ); 
            
            struct ListNode *temp=new ListNode(val3);
            temp->next=head;
            head=temp;
            
            carry=(val1+val2+carry)/10;
        }
        return head;
    }
};
//Reversing LL1 and LL2
//3 pass basically
//SC-->O(1)
//TC--> O(n)
