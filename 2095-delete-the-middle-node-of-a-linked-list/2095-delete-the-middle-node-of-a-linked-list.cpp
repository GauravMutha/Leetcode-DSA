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
    ListNode* deleteMiddle(ListNode* head) {
        struct ListNode *fast=head,*slow=head,*s_tail=NULL;
        if(head->next==NULL) return NULL;
        while(fast && fast->next){
            s_tail=slow;
            slow=slow->next;
            fast=fast->next;
            if(fast && fast->next) fast=fast->next;
        }
        s_tail->next=slow->next;
        return head;
    }
};

//1 pass solution