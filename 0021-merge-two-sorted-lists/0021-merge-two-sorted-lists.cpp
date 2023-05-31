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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        else if(list2==NULL) return list1;
        
        auto dummy = new ListNode(-1);
        auto linker=dummy, ptr1=list1, ptr2=list2;
        while(ptr1 && ptr2){
            if(ptr1->val<=ptr2->val){
                linker->next=ptr1;
                ptr1=ptr1->next;
                linker=linker->next;
            }
            else{
                linker->next=ptr2;
                ptr2=ptr2->next;
                linker=linker->next;
            }
        }
        if(ptr1==NULL) linker->next=ptr2;
        else if(ptr2==NULL) linker->next=ptr1;
        
        return dummy->next;
    }
};