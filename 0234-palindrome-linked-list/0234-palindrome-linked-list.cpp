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
        struct ListNode *f=head,*s=head;
        stack<int>st;
        while(f && f->next){
            st.push(s->val);
            f=f->next->next;
            s=s->next;
        }
        if(f) s=s->next; //odd length
        for(;s!=NULL;s=s->next){
            if(s->val!=st.top()) return false;
            st.pop();
        }
        return true;
    }
};
//More concise than previous
//TC-->O(n) + 2 pass;
//SC-->O(n)