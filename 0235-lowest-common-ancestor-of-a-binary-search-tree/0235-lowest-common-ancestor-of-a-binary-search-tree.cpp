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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto curr=root;
        while(1){
            if(curr->val>max(p->val,q->val)) curr=curr->left; //greater than p,q
            else if(curr->val<min(p->val,q->val))curr=curr->right; //smaller than p,q
            else break;
        }
        return curr;
    }
};