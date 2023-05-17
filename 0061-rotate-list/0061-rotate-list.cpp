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

//Same logic but using recursion
class Solution {
public:
    void helper(ListNode* &p,int count,int target,ListNode* &tail,ListNode* &joint){
        if(p==NULL) return;

        count++;
        if(p->next==NULL) joint=p;
        if(count==target) tail=p;
        
        p=p->next;
        helper(p,count,target,tail,joint);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        int total=0;
        auto p=head;
        while(p) p=p->next , total++;
        k%=total;
        if(k==0) return head;
        
        p=head;
        ListNode *tail,*joint;
        helper(p,0,total-k,tail,joint);
        cout<<total-k;
        joint->next=head;
        head=tail->next;
        tail->next=NULL;
        
        return head;
    }
};