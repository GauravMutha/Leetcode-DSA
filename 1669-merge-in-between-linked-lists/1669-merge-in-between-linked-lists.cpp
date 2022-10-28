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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        struct ListNode *left=list1,*right1=list1,*right2=list2;
        for(int i=0;i<b;i++){
            if(i<a-1) left=left->next;
            right1=right1->next;
        }
        while(right2 && right2->next) right2=right2->next;
        
        left->next=list2;
        right2->next=right1->next;
        list2=list1;
        
        return list1;
    }
};

//2 pass solution