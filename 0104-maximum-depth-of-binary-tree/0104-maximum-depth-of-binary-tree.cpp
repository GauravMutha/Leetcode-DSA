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
//More concise
class Solution {
public:
    int preorder(TreeNode* curr){
        if(curr==NULL) return 0;
        
        int leftRet=preorder(curr->left);
        int rightRet=preorder(curr->right);
        
        return (1+max(leftRet,rightRet));
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return preorder(root);
    }
};