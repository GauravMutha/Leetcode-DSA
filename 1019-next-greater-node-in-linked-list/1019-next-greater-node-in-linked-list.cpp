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
        vector<int>vec;
        stack<int>st;
        
        for(auto p=head;p;p=p->next){
            vec.push_back(p->val);
        }
        
        vector<int>res(vec.size(),0);
        for(int i=vec.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=vec[i]) st.pop();
            if(!st.empty()) res[i]=st.top();
            st.push(vec[i]);
        }
        return res;
    }
};

//2 pass
//SC-->O(n)
//TC->O(n)