/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Without Calculating difference of length
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        
        auto a=headA , b=headB;
        while(a != b){
            a=(a==NULL) ? a=headB : a->next;
            b=(b==NULL) ? b=headA : b->next;
        }
        return a;
    }
};