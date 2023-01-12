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

static int mod= 1e9+7;
class Solution {
public:
    long long ans=INT_MIN;
    long long calculate(TreeNode* root){
        if(!root) return 0;
        return (long long)root->val+calculate(root->left)+calculate(root->right);
    }
    long long dfs(TreeNode* root,long long &total){
        if(!root) return 0;
        long long leftRet=dfs(root->left,total);
        long long rightRet=dfs(root->right,total);
        ans=max(max(leftRet*(total-leftRet),rightRet*(total-rightRet)),ans);
        
        return leftRet+rightRet+root->val;
    }
    int maxProduct(TreeNode* root) {
        long long total=calculate(root);
        dfs(root,total);
        
        return ans%mod;
    }
};