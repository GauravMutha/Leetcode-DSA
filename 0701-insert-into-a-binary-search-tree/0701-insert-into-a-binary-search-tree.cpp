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
//Iterative
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr=root , *node=new TreeNode(val);
        if(root==NULL) return node;
        while(curr){
            if(val<curr->val){
                if(curr->left) curr=curr->left;
                else { curr->left=node; break; }
            }
            else{
                if(curr->right) curr=curr->right;
                else { curr->right=node; break; }
            }
        }
        
        
        return root;
    }
};