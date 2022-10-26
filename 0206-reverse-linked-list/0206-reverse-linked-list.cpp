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
    ListNode* reverseList(ListNode* head) {
        struct ListNode *p,*q{NULL},*r{NULL};
        p=head;
        
        while(p!=NULL){
            r=q;
            q=p;
            p=p->next;
            
            q->next=r;
        }
        head=q;
        return q;
    }
};

//Method 1 -- constant SC  and it is one pass solution of O(n) TC 