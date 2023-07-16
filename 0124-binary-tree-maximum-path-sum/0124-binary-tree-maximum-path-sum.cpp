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
//Slightly different implementation of previous code
class Solution {
private:
    int maxSum1=INT_MIN,maxSum2=INT_MIN;
public:
    int helper(TreeNode* curr){
        if(curr==NULL) return 0;
        
        int leftRet=helper(curr->left);
        int rightRet=helper(curr->right);
        
        int maxOfLR=max(leftRet,rightRet);
        int max_nodeIncluded=max(curr->val,curr->val+maxOfLR);
        int max_nodeExcluded=curr->val+leftRet+rightRet;
        
        maxSum1=max(maxSum1,max_nodeIncluded);
        maxSum2=max(maxSum2,max_nodeExcluded);
        
        return max_nodeIncluded;
        
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return max(maxSum1,maxSum2);
    }
};