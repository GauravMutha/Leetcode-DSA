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
        struct ListNode *first=list1,*second=list2,*list3=NULL,*last=NULL;
        if(list1 ==NULL && list2==NULL) return NULL;
        else if(list1==NULL) return list2;
        else if (list2==NULL) return list1;
        if(list1->val < list2->val){
            list3=last=first;
            first=first->next;
        }
        else{
            list3=last=second;
            second=second->next;
        }
        
        while(first && second){
            if(first->val < second->val){
                last->next=first;
                last=first;
                first=first->next;
            }
            else {
                last->next=second;
                last=second;
                second=second->next;
            }            
        }
        if(first!=NULL) last->next=first;
        else if(second!=NULL) last->next=second;
        
        return list3;
    }
};

//iterative