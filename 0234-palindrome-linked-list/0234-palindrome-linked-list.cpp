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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        stack<int>st;
        ListNode *f=head, *s=head;
        while(f && f->next){
            st.push(s->val);
            s=s->next ,f=f->next->next;
        }
        if(f) s=s->next;
        for(;s;s=s->next){
            if(s->val!=st.top()) return false;
            st.pop();
        }
        
        return true;
    }
};