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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode *dummy, *p=head;
        dummy=new ListNode(-100,head);
        int len=0;
        while(p){
            len++;
            p=p->next;
        }
        p=dummy;
        for(int i=1;i<=len-n;i++)
            p=p->next;
        p->next=p->next->next;
        return dummy->next;
    }
};

//2 pass