/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Iterative
//"BST-OPTIMISED"
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr=root;
        while(1){
            if(p->val<curr->val && q->val<curr->val)
                curr=curr->left;
            
            else if(p->val>curr->val && q->val>curr->val)
                curr=curr->right;
            
            else break;
        }
        return curr;
    }
};