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
    ListNode* reverseList(ListNode* head) {
        vector<int>temp;
        struct ListNode *p;
        p=head;
        while(p){
            temp.push_back(p->val);
            p=p->next;
        }
        p=head;
        for(int i=temp.size()-1;i>=0;i--){
            p->val=temp[i];
            p=p->next;
        }
        return head;
    }
};

//Method 1 -- requires space - o(n) and it is two paas solution