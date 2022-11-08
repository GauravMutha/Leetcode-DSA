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
        struct ListNode dummy(0,head), *f , *b;
        f=b=&dummy;
        
        while(f && f->next){
            if(n-- > 0) f=f->next;
            else f=f->next , b=b->next;
        }
        b->next=b->next->next;
        return dummy.next;
    }
};

//Two pointers + one pass solution