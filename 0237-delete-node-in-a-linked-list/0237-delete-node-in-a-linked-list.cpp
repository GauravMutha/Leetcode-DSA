/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        struct ListNode* i=node , *j=i->next;
        
        while(j!=NULL){
            i->val=j->val;
            if(j->next==NULL) i->next=NULL;
            else i=j ;
             j=j->next;
        }
    }
};