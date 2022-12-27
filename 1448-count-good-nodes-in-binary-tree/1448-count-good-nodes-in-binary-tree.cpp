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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        int count=0,maxi=INT_MIN;
        q.push({root,maxi});
        while(!q.empty()){
            TreeNode* curr=q.front().first;
            int num=q.front().second;
            q.pop();
            if(curr->val>=num) count++;
            maxi=max(curr->val,num);
            if(curr->left) q.push({curr->left,maxi});
            if(curr->right) q.push({curr->right,maxi});
        }
        
        return count;
    }
};