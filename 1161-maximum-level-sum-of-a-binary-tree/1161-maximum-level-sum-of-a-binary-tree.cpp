/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//BFS
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* temp;
        int ans=0,maxSum=INT_MIN,level=1;
        while(q.size()){
            int sz=q.size(),sum=0;
            for(int i=0;i<sz;i++){
                temp=q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                sum+=temp->val;
                q.pop();
            }
            if(sum>maxSum) ans=level , maxSum=sum;
            level++;
        }
        return ans;
    }
};