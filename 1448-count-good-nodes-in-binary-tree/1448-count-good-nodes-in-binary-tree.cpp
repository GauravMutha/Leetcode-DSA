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
    int ans=0;
    void helper(TreeNode* curr , int maxi){
        if(curr==NULL) return;
        maxi=max(curr->val,maxi);
        if(curr->val>=maxi){
            ans++;
        }
        
        helper(curr->left,maxi);
        helper(curr->right,maxi);

    }
    int goodNodes(TreeNode* root) {
        int maxi=INT_MIN;
        helper(root,maxi);
        return ans;
    }
};