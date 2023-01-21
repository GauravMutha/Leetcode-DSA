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
//ITERATIVE
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr=root;
        while(curr){
            if(val<curr->val)
                curr=curr->left;
            else if(val>curr->val)
                curr=curr->right;
            else return curr;
        }
        
        return curr;
    }
};