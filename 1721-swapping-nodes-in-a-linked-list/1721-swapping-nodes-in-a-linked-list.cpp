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
    ListNode* swapNodes(ListNode* head, int k) {
        struct ListNode  *l=NULL,*r=head,*p=head;
        int count=0,temp=0;    
        while(p){
            count++;
            if(count==k) l=p;
            p=p->next;
        }
        for(int i=0;i<count-k;i++){
            r=r->next;
        }
        if(l==r) return head;
        temp=l->val;
        l->val=r->val;
        r->val=temp;
        
        return head;
    }
};

//THE QUESTION SAYS SWAP THE VALUES OF THE NODES AND THE ENTIRE NODE THEMSELVES!
//2 pass solution