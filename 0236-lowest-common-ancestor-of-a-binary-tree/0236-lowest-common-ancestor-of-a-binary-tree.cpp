/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Optimised DFS postOrder
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val==p->val || root->val==q->val) return root;
        
        auto leftRet=lowestCommonAncestor(root->left,p,q);
        auto rightRet=lowestCommonAncestor(root->right,p,q);
        
        if(leftRet && rightRet) return root;
        else if(!leftRet && !rightRet) return NULL;
        
        return leftRet==NULL?rightRet : leftRet;
    }
};