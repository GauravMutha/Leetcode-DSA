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
//REVISE
//#1 -> Reversal by values using extra space
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto ptr=head;
        vector<int>values;
        while(ptr!=NULL){
            values.push_back(ptr->val);
            ptr=ptr->next;
        }
        int i=values.size()-1;
        ptr=head;
        while(ptr!=NULL){
            ptr->val=values[i--];
            ptr=ptr->next;
        }
        return head;
    }
};