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
    int maxSum=INT_MIN;
    int helper(TreeNode* node){
        if(node==NULL) return 0;
        
        int leftRet=helper(node->left);
        int rightRet=helper(node->right);
        int maxLR=max(leftRet, rightRet);
        
        int nonDomeSum=max(maxLR+node->val,node->val);
        int domeSum=node->val+leftRet+rightRet;
        
        maxSum=max(maxSum,max(domeSum,nonDomeSum));
        return nonDomeSum;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};