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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        struct ListNode *p=head , *l=NULL, *r=NULL;
        vector<int>vec;
        int count=0;
        while(p && count!=right){
            count++;
            if(count>=left && count<=right){
                if(count==left) l=p;
                if(count==right) r=p;
                vec.push_back(p->val);
            }
            p=p->next;
        }
        p=l;
        for(int i=vec.size()-1;i>=0 && p; i--,p=p->next){
            p->val=vec[i];
        }
        return head;
    }
};

//Using extra space
//TC ->O(n) and worst case sc->O(n)