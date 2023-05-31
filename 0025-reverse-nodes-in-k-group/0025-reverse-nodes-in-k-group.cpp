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
//Recursive
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode *p=head , *q,*r;
        
        //Lets check there is set of k block ahead or not
        for(int i=0;i<k;i++){
            if(p==NULL) return head;
            else p=p->next;
        }
        /*we have set of k block so we reverse it iterati
        -vely using 3 pointer method q---p---r*/
        q=NULL , p=head , r=NULL;
        for(int i=0;i<k;i++){
            r=p->next;
            p->next=q;
            q=p;
            p=r;        
        }
        head->next=reverseKGroup(p,k);
        return q;
    }
};