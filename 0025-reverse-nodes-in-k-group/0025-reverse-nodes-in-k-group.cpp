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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        
        auto dummy= new ListNode(-1);
        dummy->next=head;
        auto tail=dummy,start=dummy,end=dummy;
        
        for(int i=0;i<k && end;i++) end=end->next;
        start=start->next;
        if(end==NULL) return head;
        
        while(end){
            auto p=start,q=start->next , r=start->next->next;
            
            // setting the links for the extreme nodes of the block
            start->next=end->next;
            tail->next=end;
            //main reversal of the block
            while(p!=end){
                q->next=p;
                p=q;
                q=r;
                if(r) r=r->next;
            }
            swap(start,end);
            tail=end;
            
            //moving start and end to the next block
            for(int i=0;i<k && end && start;i++) end=end->next , start=start->next;
        }
        
        return dummy->next;
    }
};