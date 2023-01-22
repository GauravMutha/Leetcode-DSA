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
//DFS
class Solution {
public:
    void inorder(TreeNode* root , TreeNode* &pre , int &ans){
        if(!root) return;
        inorder(root->left,pre,ans);
        if(pre!=NULL) ans=min(ans,abs(pre->val-root->val));
        pre=root;
        inorder(root->right,pre,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* pre=NULL;
        int ans=INT_MAX;
        inorder(root,pre,ans);
        return ans;
    }
};