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
//PREORDER
//MORE CONCISE
//UPPER BOUNDS LOWER BOUNDS CONCEPT IS USED RATHER THAN LONG_MIN AND PRE
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root,NULL,NULL);
    }
    bool dfs(TreeNode* root, TreeNode* minNode , TreeNode* maxNode){
        if(!root) return true;
        if((minNode&& root->val<=minNode->val)||(maxNode && root->val>=maxNode->val))
            return false;
        
        return dfs(root->left,minNode,root) && dfs(root->right,root,maxNode);
    }
};