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
//BST-OPTIMIZED DFS
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int ans=(root->val>=low && root->val<=high) ? root->val :0;
        if(root->val>low) ans+= rangeSumBST(root->left,low,high);
        if(root->val<high) ans+= rangeSumBST(root->right,low,high);
        
        return ans;
    }
};