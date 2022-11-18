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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>res;
        stack<int>st;
        
        for(auto p=head;p;p=p->next){
            while(!st.empty() && res[st.top()]<p->val){
                res[st.top()]=p->val;
                st.pop();
            }
            st.push(res.size());
            res.push_back(p->val);
        }
        while(!st.empty()) res[st.top()]=0 , st.pop();
        return res;
    }
};

//1 pass
//SC-->O(n)
//TC->O(n)