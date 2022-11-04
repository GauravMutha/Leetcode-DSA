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
        struct ListNode *small,*large,*small_head,*large_head;
        small=new ListNode(-1);
        large= new ListNode(-1);
        small_head=small;
        large_head=large;
        
        while(head){
            if(head->val<x){
                small->next=head;
                small=small->next;
                head=head->next;
                small->next=NULL;
            }
            else{
                large->next=head;
                large=large->next;
                head=head->next;
                large->next=NULL;
            }
        }
        small->next=large_head->next;
        return small_head->next;
    }
};

//O(1) space Two pointers