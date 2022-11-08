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
    ListNode* rotateRight(ListNode* head, int k) {
        struct ListNode *p=head, *f, *b ,dummy(-1,head);
        f=b=&dummy;
        int len=0;
        while(p) p=p->next , len++;
        if(len)k=k%len;
        if(k==0) return head;
        
        while(f && f->next){
            if(k-- > 0) f=f->next;
            else f=f->next , b=b->next;
        }
        dummy.next=b->next;
        b->next=f->next;
        f->next=head;
        head=dummy.next;
        
        return dummy.next;
    }
};