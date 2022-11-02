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
        unordered_map<ListNode* , int>addressMap;
        while(a!=NULL){
            addressMap[a]++;
            a=a->next;
        }
        while(b!=NULL){
            if(addressMap[b]>0) return b;
            b=b->next;
        }
        return NULL;
    }
};

//Previous solution uses no space
//this one uses O(n) space where n is the number of nodes in LLA or LLB