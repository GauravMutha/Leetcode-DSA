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
        head=head->next;
        struct ListNode *j=head,*i=head;
        while(i!=NULL){
            int sum=0;
            j=i;
            while(j->val!=0){
                sum+=j->val;
                j=j->next;
            }
            i->val=sum;
            i->next=j->next;
            i=i->next;
        }
        return head;
    }
};