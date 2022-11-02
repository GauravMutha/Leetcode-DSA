/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        struct ListNode *a=headA , *b=headB;
        int la=0,lb=0,diff=0;
        while(a) a=a->next , la++;
        while(b) b=b->next , lb++;
        if(a!=b) return NULL;
        a=headA, b=headB;
        diff=abs(la-lb);
        if(la>lb){
            while(diff--)
                a=a->next;
        }
        else {
            while(diff--)
                b=b->next;
        }
        while(a!=b)
            a=a->next , b=b->next;
        return a;
    }
};

//Bit longer but this uses the constant space + O(n) TC