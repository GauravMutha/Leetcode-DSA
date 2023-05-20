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
//Based on that naive solution but a better,concise, recursive version
//Uses only implicit space
class Solution {
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        flatten(root->right);        
        flatten(root->left);
        
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};