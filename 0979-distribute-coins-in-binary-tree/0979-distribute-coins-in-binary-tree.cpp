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
//PostOrder DFS
class Solution {
public:
    int moves=0;
    int helper(TreeNode* node){
        if(node==NULL) return 0;
        int left=helper(node->left);
        int right=helper(node->right);
        moves+=abs(left)+abs(right);
        
        return left+right+node->val-1;
    }
    int distributeCoins(TreeNode* root) {
        helper(root);
        return moves;
    }
};