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
        struct ListNode *node=head;
        int count=0;
        for(auto p=head;p!=NULL;p=p->next) count++;
        if(count<2) return NULL;
        for(int i=0;i<count/2 -1;i++){
            node=node->next;
        }
        node->next=node->next->next;
        return head;
    }
};

//2 pass solution