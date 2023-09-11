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
//Striver sheet
class Solution {
public:
    int domePath=-1;
    int helper(TreeNode* root){
        
        if(root==NULL) return 0;
        
        int leftRet=helper(root->left);
        int rightRet=helper(root->right);
        
        domePath=max(domePath,leftRet+rightRet);
        
        return (1+max(leftRet,rightRet));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return max(helper(root)-1,domePath);
    }
};