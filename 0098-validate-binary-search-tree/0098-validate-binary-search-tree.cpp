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
//Simple Inorder
class Solution {
public:
    bool inorder(TreeNode* curr,TreeNode*& pre){
        if(curr==NULL) return true;
        
        if(!inorder(curr->left,pre)) return false;
        
        else if(pre!=NULL && pre->val>=curr->val) return false;
        pre=curr;
        
        if(!inorder(curr->right,pre)) return false;
        
        return true;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* pre=NULL;
        return inorder(root,pre);
    }
};