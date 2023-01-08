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
//DFS -PreOrder- Without helper
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        if(d==1) return new TreeNode(val,root,NULL);
        if(d==2){
            root->left=new TreeNode(val,root->left,NULL);
            root->right=new TreeNode(val,NULL,root->right);
        }
        else{
            if(root->left) addOneRow(root->left,val,d-1);
            if(root->right) addOneRow(root->right,val,d-1);
        }
        
        return root;
    }
};