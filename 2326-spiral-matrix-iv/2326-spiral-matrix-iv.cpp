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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        struct ListNode *p=head;
        int minr=0,minc=0,maxr=m-1,maxc=n-1;
        vector<vector<int>>res(m,vector<int>(n,-1));
        while(p){
            for(int i=minr,j=minc;j<=maxc && p ;j++,p=p->next)
                res[i][j]=p->val;
            minr++;
            for(int i=minr,j=maxc;i<=maxr && p ;i++,p=p->next)
                res[i][j]=p->val;
            maxc--;
            for(int i=maxr,j=maxc;j>=minc && p;j--,p=p->next)
                res[i][j]=p->val;
            maxr--;
            for(int i=maxr,j=minc;i>=minr && p;i--,p=p->next)
                res[i][j]=p->val;
            minc++;
        }
        return res;
    }
};