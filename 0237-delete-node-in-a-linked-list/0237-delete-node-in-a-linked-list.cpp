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
        struct ListNode *temp=node->next;
        *(node)=*(node->next);
        delete temp;
    }
};

//O(1) TC  and it also frees up the memory