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
    int getDecimalValue(ListNode* head) {
        int res=0;
        struct ListNode* q;
        q=head;
        while(q!=NULL){
            if(q->val) res|=1;
            res<<=1;
            q=q->next;
        }
        res>>=1;
        return (res);
    }
};

//Constant space