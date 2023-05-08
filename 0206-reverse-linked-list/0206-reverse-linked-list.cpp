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
//REVISE
//#2-> Reversal by values without using explicit space - using recursion
class Solution {
public:
    int halfNodes=0;
    void helper(ListNode* &f , ListNode* &b,int count){
        if(b==nullptr){
            halfNodes=count/2;
            return;
        }
        count++;
        helper(f,b->next,count);
        if(count>halfNodes){
            swap(f->val,b->val);
            f=f->next;
        }
    } 
    ListNode* reverseList(ListNode* head) {
        auto f=head;
        auto b=head;
        helper(f,b,0);
        
        return head;
        
    }
};