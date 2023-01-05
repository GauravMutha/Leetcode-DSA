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
// dfs preorder
class Solution {
public:
    int ans=0;
    void dfs(TreeNode* curr, int depth, int& maxDepth){
        if(curr==NULL) return;
        if(depth>maxDepth){
            maxDepth=depth;
            ans=curr->val;
        }
        dfs(curr->left,depth+1,maxDepth);
        dfs(curr->right,depth+1,maxDepth);
    }
    int findBottomLeftValue(TreeNode* root) {
        int depth=0,maxDepth=-1;
        dfs(root,depth,maxDepth);
        return ans;
    }
};