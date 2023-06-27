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
        if(curr==NULL || curr->val==p->val || curr->val==q->val) return curr;
        
        auto rightRet= (curr->val>min(p->val,q->val))?
            lowestCommonAncestor(curr->left,p,q):NULL;
        
        auto leftRet= (curr->val<max(p->val,q->val))?
            lowestCommonAncestor(curr->right,p,q):NULL;
        
        if(leftRet && rightRet) return curr;
        
        return (leftRet)?leftRet : rightRet;
    }
};