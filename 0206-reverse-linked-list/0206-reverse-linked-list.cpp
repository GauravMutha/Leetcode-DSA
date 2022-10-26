// *
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };

class Solution {
public:
    void recReverse(ListNode* q,ListNode* p,ListNode* &j){
        if(p!=NULL){
            recReverse(p,p->next,j);
            p->next=q;
        }
        else {
            j=q;
        }
    }
    ListNode* reverseList(ListNode* head) {
        struct ListNode* q=NULL,*j=NULL;
        recReverse(q,head,j);
        head=j;
        return head;
    }
};

//Method 2 -- constant SC  and it is one pass solution of O(n) TC recusrive