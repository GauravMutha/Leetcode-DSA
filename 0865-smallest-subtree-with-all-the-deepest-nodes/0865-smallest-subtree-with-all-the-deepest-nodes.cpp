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
    int deepest=0;
    TreeNode* ans=nullptr;
    int dfs(TreeNode* curr , int level){
        if(curr==NULL) return level;
        
        int leftDepth=dfs(curr->left,level+1);        
        int rightDepth=dfs(curr->right,level+1);
        
        int maxLocal=max(leftDepth,rightDepth);
        deepest = max(deepest , maxLocal);
        
        if(leftDepth==deepest && rightDepth==deepest) ans=curr;
        
        return maxLocal;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};