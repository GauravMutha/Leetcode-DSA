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
        struct ListNode *f=head,*s=head,*p=NULL;
        stack<int>st;
        if(head->next==NULL) return true;
        while(f->next && f->next->next){
            f=f->next->next;
            s=s->next;
        }
        if(f->next==NULL) *s=*(s->next); 
        else if(f->next->next==NULL) s=s->next;
        p=head;
        bool flag=false;
        for(;p!=NULL;p=p->next){
            if(p==s) flag=true;
            if(!flag) st.push(p->val);
            else{
                if(st.top()!=p->val) return false;
                st.pop();
            }
        }
        return true;
    }
};

//TC-->O(n) + 2 pass
//SC-->O(n)