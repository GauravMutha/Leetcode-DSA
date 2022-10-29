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
        struct ListNode *first=NULL,*second=NULL;
        for(auto p=head;p!=NULL;p=p->next){
            if(second!=NULL) second=second=second->next;
            
            if(--k==0){
                first=p;
                second=head;
            }
        }
        swap(first->val,second->val);
        return head;
    }
};

//THE QUESTION SAYS SWAP THE VALUES OF THE NODES AND THE ENTIRE NODE THEMSELVES!
//1 pass solution