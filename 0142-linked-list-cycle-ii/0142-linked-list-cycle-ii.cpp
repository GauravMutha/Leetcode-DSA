/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Using map
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool> m;
        
        for(auto curr=head;curr;curr=curr->next){
            int prevSz=m.size();
            m[curr]=true;
            if(m.size()==prevSz) return curr;
        }
        
        return NULL;
    }
};