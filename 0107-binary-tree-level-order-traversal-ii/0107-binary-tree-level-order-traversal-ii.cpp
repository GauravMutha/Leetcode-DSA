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
//dfs Without reversing
//bfs will have follow same concept to avoid reversal
class Solution {
public:
    int depth(TreeNode* root){
        if(!root) return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
    void dfs(TreeNode* curr , int level , vector<vector<int>> &ans){
        if(curr==NULL) return;
        ans[ans.size()-level-1].push_back(curr->val);
        
        dfs(curr->left,level+1,ans);
        dfs(curr->right,level+1,ans);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d=depth(root);
        vector<vector<int>>ans(d,vector<int>{});
        dfs(root,0,ans);
        return ans;
    }
};