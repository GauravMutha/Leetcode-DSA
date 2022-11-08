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
        return recurser(l1,l2,0);
    }
    ListNode* recurser(ListNode *l1 , ListNode *l2 , int carry){
        if(!l1 && !l2 && !carry) return NULL;
        
        int val3=(l1? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        struct ListNode *curr = new ListNode(val3%10);
        curr->next=recurser(l1 ? l1->next : NULL,l2 ? l2->next:NULL,val3/10);
        return curr;
    }
};