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
    ListNode* partition(ListNode* head, int x) {
        vector<int>left,right;
        struct ListNode *p=head;
        while(p){
            if(p->val<x) left.push_back(p->val);
            else right.push_back(p->val);
            p=p->next;
        }
        p=head;
        for(auto elem : left){
            p->val=elem;
            p=p->next;
        }
        for(auto elem : right){
            p->val=elem;
            p=p->next;
        }
        return head;
    }
};

//uses extra space SC ->O(n) where n is the number of nodes
//TC-> O(n) 2 pass