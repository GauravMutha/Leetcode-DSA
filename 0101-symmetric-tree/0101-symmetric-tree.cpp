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
    bool symmetric=true;
    void helper(TreeNode* curr1,TreeNode* curr2){
        if(curr1==NULL && curr2==NULL) return;
        else if(((curr1==NULL) ^ (curr2==NULL)) || (curr1->val!=curr2->val))
            symmetric=false;
        if(symmetric) helper(curr1->left,curr2->right);
        if(symmetric) helper(curr1->right,curr2->left);
    }
    bool isSymmetric(TreeNode* root) {
        helper(root->left,root->right);
        return symmetric;
    }
};