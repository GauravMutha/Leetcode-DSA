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
//INORDER- SLIGHTLY BETTER
class Solution {
public:
    int kthSmallest(TreeNode* root, int& k) {
        if(!root) return -1;
        
        int L= kthSmallest(root->left, k);
        if(L!=-1) return L;
        
        k--;
        
        if(k==0) return root->val;
        
        int R= kthSmallest(root->right, k);
        if(R!=-1) return R;
        
        return -1;
    }
};