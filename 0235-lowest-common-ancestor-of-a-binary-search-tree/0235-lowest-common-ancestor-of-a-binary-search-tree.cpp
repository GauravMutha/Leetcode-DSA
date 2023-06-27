/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* curr, TreeNode* p, TreeNode* q) {
        if(curr==NULL) return NULL;
        
        if(curr->val > max(p->val,q->val))
            return lowestCommonAncestor(curr->left,p,q);
        else if(curr->val < min(p->val,q->val))
            return lowestCommonAncestor(curr->right,p,q);
        else  return curr;
    }
};