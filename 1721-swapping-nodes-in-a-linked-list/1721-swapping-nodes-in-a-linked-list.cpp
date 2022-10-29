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
        struct ListNode *slow=head,*fast=head , *first=NULL,*second=NULL;
        for(int i=0;i<k-1;i++){ 
            fast=fast->next;
        }
        first=fast;
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        second=slow;
        swap(second->val,first->val);
        return head;
    }
};

//THE QUESTION SAYS SWAP THE VALUES OF THE NODES AND THE ENTIRE NODE THEMSELVES!
//2 pass solution OPTIMIZED