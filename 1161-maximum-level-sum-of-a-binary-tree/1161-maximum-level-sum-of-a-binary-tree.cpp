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
//DFS
class Solution {
public:
    void dfs(TreeNode* root , int level,map<int,int>&m){
        if(root==NULL) return;
        m[level]+=root->val;
        dfs(root->left,level+1,m);
        dfs(root->right,level+1,m);
    }
    int maxLevelSum(TreeNode* root) {
        int maxSum=INT_MIN,ans=0;
        map<int,int>m;
        dfs(root,1,m);
        for(auto &[key,values]:m){
            if(values>maxSum) maxSum=values , ans=key;
        }
        return ans;
    }
};