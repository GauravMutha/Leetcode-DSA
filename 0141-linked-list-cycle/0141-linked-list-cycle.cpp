/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode* , int>addressMap;
        int prevSize=0;
        struct ListNode* p=head;
        while(p){
            prevSize=addressMap.size();
            addressMap[p]++;
            if(prevSize==addressMap.size()) return true;
            p=p->next;
        }
        return false;
    }
};
//HASH MAP

//SC -> O(N) TC O(N)