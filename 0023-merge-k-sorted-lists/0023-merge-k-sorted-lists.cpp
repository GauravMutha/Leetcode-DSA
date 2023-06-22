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
//Using priority queue + removing pairs and using comparator
struct compare{
  bool operator()(const ListNode* l1 , const ListNode* l2){
      return l1->val>l2->val;
  } 
};
class Solution {
private:
    priority_queue <ListNode*, vector<ListNode*>, compare > pq;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        auto dummy=new ListNode(-1) , curr=dummy;
        for(int i=0;i<n;i++) if(lists[i]) pq.push(lists[i]) , dummy->next=pq.top();
        
        while(pq.size()){
            auto node=pq.top();
            pq.pop();
            
            curr->next=node;
            curr=node;
            
            if(node->next) pq.push(node->next);
        }
        curr->next=NULL;
        return dummy->next;
    }
};