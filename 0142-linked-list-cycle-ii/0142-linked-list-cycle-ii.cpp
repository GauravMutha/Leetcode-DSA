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
    ListNode *detectCycle(ListNode *head) {
        struct ListNode* p=head;
        unordered_map<ListNode* , int>m;
        while(p){
            int prev=m.size();
            m[p]++;
            if(m.size()==prev) return p;
            p=p->next;
        }
        return NULL;
    }
};