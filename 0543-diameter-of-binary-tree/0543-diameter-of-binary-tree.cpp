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
//Similar to maximum sum path
class Solution {
private:
    int maxSum1=-1;
public:
    int helper(TreeNode* curr){
        if(curr==NULL) return 0;
        int leftRet=helper(curr->left);
        int rightRet=helper(curr->right);
        
        maxSum1=max(maxSum1,leftRet+rightRet);
        
        return 1+max(leftRet,rightRet);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxSum2=helper(root);
        return max(maxSum1,maxSum2-1);
    }
};