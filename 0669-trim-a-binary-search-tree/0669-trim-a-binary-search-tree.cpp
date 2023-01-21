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
//DFS- BST OPTIMIZED
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return NULL;
        
        TreeNode* L= (root->val >low) ? trimBST(root->left,low,high) : NULL;
        TreeNode* R= (root->val<high)? trimBST(root->right,low,high) : NULL;
        
        if(root->val<low) root->left=NULL , root=R;
        else if(root->val>high) root->right=NULL , root=L;
        else if(root->val>=low && root->val<=high){
            root->left=L;
            root->right=R;
        }
        
        return root;
    }
};