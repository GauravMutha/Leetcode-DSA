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

//More concise preorder than previous one
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL && root->val==target){
            root=NULL;
            return root;
        }
        TreeNode* lchild=removeLeafNodes(root->left,target);
        TreeNode* rchild=removeLeafNodes(root->right,target);
        root->left=lchild;
        root->right=rchild;
        if(root->left==NULL && root->right==NULL && root->val==target){
            return NULL;
        }
        return root;
    }
};