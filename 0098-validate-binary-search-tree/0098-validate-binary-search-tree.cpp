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
    long pre=LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool L= isValidBST(root->left);
        if(pre!=LONG_MIN) L=L&& (root->val>pre);
        pre=root->val;
        
        bool R= isValidBST(root->right);
        
        return R&&L;
    }
};