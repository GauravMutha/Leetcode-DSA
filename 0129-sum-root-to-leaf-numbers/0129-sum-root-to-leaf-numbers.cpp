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
//DFS - Preorder  like previous one - More Concise
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
    int dfs(TreeNode* curr, int sum){
        if(!curr) return 0;
        sum=curr->val+10*sum;
        if(!curr->left && !curr->right) return sum;
        return dfs(curr->left,sum) + dfs(curr->right,sum);
    }
};