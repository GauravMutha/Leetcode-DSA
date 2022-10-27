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
    ListNode* mergeNodes(ListNode* head) {
        struct ListNode *j=head,*i=head;
        while(i!=NULL && i->next!=NULL){
            int sum=0;
            do{
                sum+=j->val;
                j=j->next;
            }while(j!=NULL && j->val!=0);
            i->val=sum;
            if(j->next==NULL) {i->next=NULL ; break;}
            i->next=j;
            i=j;
        }
        return head;
    }
};