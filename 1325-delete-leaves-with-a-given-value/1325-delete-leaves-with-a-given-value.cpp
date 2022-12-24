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
//preorder
class Solution {
public:
    void helper(TreeNode* curr, TreeNode* parent , int target){
        if(curr==NULL) return;
        if(curr->left==NULL && curr->right==NULL && curr->val==target){
            if(parent->left==curr) parent->left=NULL;
            else if(parent->right==curr) parent->right=NULL;
            
            return;
        }
        helper(curr->left,curr,target);
        helper(curr->right,curr,target);
        if(curr->left==NULL && curr->right==NULL && curr->val==target){
            if (parent==NULL) return;
            if(parent->left==curr) parent->left=NULL;
            else if(parent->right==curr) parent->right=NULL;
            
            return;
        }
        
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        helper(root,NULL,target);
        if(root->val==target && root->left==NULL && root->right==NULL) return NULL;
        return root;
    }
};