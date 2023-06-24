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
//Preorder
class Solution {
public:
    bool isValidBST(TreeNode* root ,long long minBound=-1e10, long long maxBound=1e10) {
        if(root==NULL) return true;
        
        if(root->val >= maxBound || root->val<=minBound) return false;
        
        if(!isValidBST(root->left,minBound,(long long)root->val)) return false;
        if(!isValidBST(root->right,(long long)root->val,maxBound)) return false;
        
        return true;
    }
};