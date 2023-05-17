/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Better Implementation of the previous logic
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        
        int lenA=1,lenB=1;
        auto a=headA , b=headB;
        while(a->next) a=a->next , lenA++;
        while(b->next) b=b->next , lenB++;
        
        if(a!=b) return NULL;
        
        int diff=abs(lenA-lenB);
        a=headA,b=headB;
        if(lenA>lenB){
            while(diff--) a=a->next;
        }
        else if(lenB>lenA){
            while(diff--) b=b->next;
        }
        while(a!=b) a=a->next , b=b->next;
        return a;
    }
};