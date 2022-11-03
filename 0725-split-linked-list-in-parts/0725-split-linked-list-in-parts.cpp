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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        struct ListNode *p=head;
        vector<ListNode*>res(k,NULL);
        int count=0,val=0,extra=0,len=0,i=0;
        while(p) len++ , p=p->next;
        val=len/k  ,extra=len%k;
        p=head;
        while(p){
            res[i++]=p;
            int currlen=1;
            while(currlen<val) p=p->next , currlen++;
            if(extra>0 && len>k) p=p->next , extra--;
            
            struct ListNode *temp=p->next;
            p->next=NULL;
            p=temp;
        }
        return res;
    }
};