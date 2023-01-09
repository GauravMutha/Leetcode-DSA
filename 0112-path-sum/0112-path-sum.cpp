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
class Solution {
public:
    bool flag=false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root,0,targetSum);
        return flag;
    }
    void dfs(TreeNode* curr,int sum,int &k){
        if(!curr) return;
        sum+=curr->val;
        if(!curr->left && !curr->right && sum==k) flag=true;
        else{
            dfs(curr->left,sum,k);
            dfs(curr->right,sum,k);
        }
     }
};