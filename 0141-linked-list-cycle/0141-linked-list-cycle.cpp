/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//using extra space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_set<ListNode*>st;
        auto p=head;
        while(p){
            int sz=st.size();
            st.insert(p);
            if(sz==st.size()) return true;
            p=p->next;
        }
        return false;
    }
};