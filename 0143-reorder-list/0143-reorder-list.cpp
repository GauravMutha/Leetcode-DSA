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
        struct ListNode *f=head ,*s=head;
        while(f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        }
        struct ListNode *preMid=s,*tail=s->next;
        while(tail->next){
            ListNode* temp=preMid->next;
            preMid->next=tail->next;
            tail->next=tail->next->next;
            preMid->next->next=temp;
        }
        
        struct ListNode *twin=preMid->next,*left=head;
        while(left!=preMid){
            preMid->next=twin->next;
            twin->next=left->next;
            left->next=twin;
            left=twin->next;
            twin=preMid->next;
        }
    }
};
//SC-->O(1) Without Stack
//TC-->O(n)