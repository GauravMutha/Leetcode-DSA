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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        struct ListNode *b=head , *f=head->next , *start ,*startHead;
        start=new ListNode(-1) , startHead=start;
        if(b->val != f->val) start->next=b , start=b;
        while(f && f->next){
            if(f->val != b->val && f->next->val!=f->val)
                start->next=f , start=f;
            b=f;
            f=f->next;
        }
        if(b->val != f->val) start->next=f , start=f;
        start->next=NULL;
        return startHead->next;
    }
};