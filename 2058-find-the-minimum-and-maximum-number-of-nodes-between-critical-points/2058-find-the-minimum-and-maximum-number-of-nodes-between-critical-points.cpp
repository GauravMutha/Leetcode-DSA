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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>res(2,-1);
        if(head==NULL && head->next==NULL) return res;
        struct ListNode *p=head->next , *q=head;
        int pre=-1,curr=0,c_pts=0,first=0,mindist=INT_MAX;
        
        //maximum distance
        while(p && p->next){
            curr++;
            if((p->val<q->val && p->val<p->next->val) || 
              ( p->val>q->val && p->val>p->next->val) ){
                c_pts++;
                if(c_pts>1) res[1]=curr-first;
                else if(c_pts==1) first=curr;
                if(pre!=-1) mindist=min(mindist,curr-pre);
                pre=curr;
            }
            q=p;
            p=p->next;
        }
        if(mindist!=INT_MAX) res[0]=mindist;
        return res;
    }
};