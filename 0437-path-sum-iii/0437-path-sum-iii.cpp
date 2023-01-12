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
//LESS OPTIMIZED DFS postorder
//BOTTOM UP O(N^2)
class Solution {
public:
    int ans=0;
    int dfs(TreeNode* root,long long k){
        if(!root) return 0;
        
        return (root->val==k) + dfs(root->left,k-root->val)+dfs(root->right,k-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return pathSum(root->left,targetSum) + pathSum(root->right,targetSum) +dfs(root,(long long)targetSum);
    }
};