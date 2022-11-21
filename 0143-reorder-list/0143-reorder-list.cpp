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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        struct ListNode *p=head ,*q=head;
        stack<ListNode*>st;
        while(p){
            st.push(p);
            p=p->next;
        }
        int sz=st.size();
        for(int i=0;i<sz/2;i++){
            ListNode* twin=st.top();
            st.pop();
            twin->next=q->next;
            q->next=twin;
            q=q->next->next;
        }
        q->next=NULL;
    }
};
//SC-->O(n) Uses Stack
//TC-->O(n)