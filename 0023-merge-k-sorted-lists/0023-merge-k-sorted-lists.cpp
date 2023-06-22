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
//Using priority queue
class Solution {
private:
    priority_queue <pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>> > pq;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size(),value;
        auto dummy=new ListNode(-1) , curr=dummy;
        for(int i=0;i<n;i++) if(lists[i]) pq.push({lists[i]->val,lists[i]}) , dummy->next=pq.top().second;
        
        while(pq.size()){
            auto node=pq.top().second;
            pq.pop();
            
            curr->next=node;
            curr=node;
            
            if(node->next) pq.push({node->next->val,node->next});
        }
        curr->next=NULL;
        return dummy->next;
    }
};