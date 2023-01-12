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
//DFS  post order
//only 1 recursive function
static int mod= 1e9+7;
class Solution {
public:
    long long ans=INT_MIN,total=0;
    long long dfs(TreeNode* root){
        if(!root) return 0;
        long long leftRet=dfs(root->left);
        long long rightRet=dfs(root->right);
        ans=max(max(leftRet*(total-leftRet),rightRet*(total-rightRet)),ans);
        
        return leftRet+rightRet+root->val;
    }
    int maxProduct(TreeNode* root) {
        total=dfs(root);
        
        dfs(root);
        
        return ans%mod;
    }
};