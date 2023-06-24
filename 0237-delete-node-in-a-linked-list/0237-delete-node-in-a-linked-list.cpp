/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        auto ahead=node->next;
        while(ahead->next){
            node->val=ahead->val;
            node=ahead;
            ahead=ahead->next;
        }
        node->val=ahead->val;
        node->next=NULL;
        delete ahead;
        return;
    }
};