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
    ListNode* middleNode(ListNode* head) {
        struct ListNode *t,*q,*p;
        p=q=head;
        while (p!=NULL && p->next!=NULL){
            q=q->next;
            p=p->next;
            p=p->next;
        }
        return q;
    }
};

//single pass o(n) solution