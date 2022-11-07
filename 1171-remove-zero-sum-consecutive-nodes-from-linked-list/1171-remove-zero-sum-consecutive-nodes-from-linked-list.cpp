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
    ListNode* removeZeroSumSublists(ListNode* head) {
        struct ListNode dummy(0,head),*p=&dummy;
        unordered_map<int,ListNode*>m;
        int prefix=0;
        while(p){
            prefix+=p->val;
            if(m.count(prefix)){
                p=m[prefix]->next;
                int temp=p->val+prefix;
                while(temp!=prefix){
                    m.erase(temp);
                    p=p->next;
                    temp+=p->val;
                }
                m[prefix]->next=p->next;
            }
            else{ m[prefix]=p; }
            p=p->next;
        }
        return dummy.next;
    }
};

//One pass