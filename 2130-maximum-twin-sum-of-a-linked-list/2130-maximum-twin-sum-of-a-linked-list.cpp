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
    int pairSum(ListNode* head) {
        vector<int>vec;
        ListNode *p=head;
        int ans=INT_MIN,len=0;
        while(p){
            len++;
            vec.push_back(p->val);
            p=p->next;
        }
        for(int i=0;i<len/2;i++)
            ans=max(ans,vec[i]+vec[len-1-i]);
        return ans;
    }
};

//TC-->O(n) Two pass
//SC-->O(n)
