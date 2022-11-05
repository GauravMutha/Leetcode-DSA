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
    ListNode* removeElements(ListNode* head, int x) {
        struct ListNode *start=NULL , *p=NULL;
        while(head){
            while(head && head->val==x) head=head->next;
            if(p==NULL) p=head , start=head;
            else {
                p->next=head;
                p=p->next;
            }
            if(head) head=head->next;
        }
        return start;
    }
};
//Without dummy