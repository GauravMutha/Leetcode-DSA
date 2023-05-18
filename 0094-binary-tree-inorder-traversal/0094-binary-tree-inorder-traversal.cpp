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
//recursive
class Solution {
public:
    void helper(TreeNode* curr,vector<int>&res){
        if(curr==NULL) return;
        helper(curr->left,res);
        res.push_back(curr->val);
        helper(curr->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        helper(root,res);
        return res;
    }
};