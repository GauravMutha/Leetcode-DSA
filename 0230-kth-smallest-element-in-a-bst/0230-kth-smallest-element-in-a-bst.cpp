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
//INORDER
class Solution {
public:
    int ans=0;
    int kthSmallest(TreeNode* root, int k) {
        int steps=0;
        inorder(root,k,steps);
        return ans;
    }
    void inorder(TreeNode* root, int& k, int& steps){
        if(!root) return;
        
        inorder(root->left,k,steps);
        if(++steps==k){
            ans=root->val;
            return;
        }
        inorder(root->right,k,steps);
    }
};