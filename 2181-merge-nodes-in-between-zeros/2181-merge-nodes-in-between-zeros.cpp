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
        while(i!=NULL){
            int sum=0;
            do{
                sum+=j->val;
                j=j->next;
            }while(j!=NULL && j->val!=0);
            i->val=sum;
            i->next=j->next;
            i=i->next;
        }
        return head;
    }
};