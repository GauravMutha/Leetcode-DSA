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
    int ans=0;
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
    void dfs(TreeNode* curr,int sum){
        if(!curr) return; 
        if(!curr->left && !curr->right){
            ans+=(curr->val+sum*10);
        }
        
        dfs(curr->left, curr->val+10*sum);
        dfs(curr->right, curr->val+10*sum);
    }
};