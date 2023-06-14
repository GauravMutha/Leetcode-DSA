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
    int ans=0,count=0;
public:
    void helper(TreeNode* curr, int& k){
        if(curr==NULL) return;
        helper(curr->left,k);
        count++;
        if(count==k)ans=curr->val;
        else helper(curr->right,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
        return ans;
    }
};