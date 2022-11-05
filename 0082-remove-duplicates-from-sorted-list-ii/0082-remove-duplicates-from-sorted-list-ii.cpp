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
    ListNode* deleteDuplicates(ListNode* head) {
        struct ListNode dummy(-1,head) , *curr;
        curr=&dummy;
        while(curr->next && curr->next->next){
            if(curr->next->val == curr->next->next->val){
                int duplicate=curr->next->val;
                while(curr->next && curr->next->val==duplicate){
                    struct ListNode *temp=curr->next;
                    curr->next=curr->next->next;
                    delete temp;
                }
            }
            else{
                curr=curr->next;
            }
        }
        return dummy.next;
    }
};

//The same code as previous but IT FREES THE MEMORY to ensure there are memory leaks
