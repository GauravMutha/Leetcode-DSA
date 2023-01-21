/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//DFS
//"BST-OPTIMISED" BY MODIFYING BT VERSION OF THIS QUESTION
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if(root->val==p->val || root->val==q->val) return root;
        
        TreeNode* L=(root->val > min(p->val,q->val))?
            lowestCommonAncestor(root->left,p,q):NULL;
        TreeNode* R=(root->val < max(p->val,q->val))?
            lowestCommonAncestor(root->right,p,q):NULL;
        
        if(L && R) return root;
        
        if(!L && !R) return NULL;
        
        return L ? L : R;
        
    }
};