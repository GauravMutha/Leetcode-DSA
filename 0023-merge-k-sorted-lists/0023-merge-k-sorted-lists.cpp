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
//Purely Iterative
//No extra space
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        if(l1->val<=l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else {
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int len=lists.size();
        while(len>1){
            for(int i=0;i<len/2;i++){
                lists[i]=mergeTwoLists(lists[i],lists[len-i-1]);
            }
            len=(len+1)/2;
        }
        return lists.front();
    }
};