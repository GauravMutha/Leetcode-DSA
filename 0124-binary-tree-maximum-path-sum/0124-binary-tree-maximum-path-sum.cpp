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
private:
    int maxSum=INT_MIN;
public:
    int helper(TreeNode* curr){
        if(curr==NULL) return 0;
        
        int leftRet=helper(curr->left);
        int rightRet=helper(curr->right);
        
        int maxOfLR=max(leftRet,rightRet);
        int max_nodeIncluded=max(curr->val,curr->val+maxOfLR);
        int max_nodeExculded=curr->val+leftRet+rightRet;
        
        maxSum=max(maxSum,max(max_nodeExculded,max_nodeIncluded));
        
        return max_nodeIncluded;
        
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};