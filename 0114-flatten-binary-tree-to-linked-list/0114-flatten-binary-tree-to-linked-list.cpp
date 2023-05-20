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
//Best Approach
//Puerly Iterative hence O(1) space
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        for(auto curr=root;curr;curr=curr->right){
            if(curr->left){
                auto p=curr->left;
                while(p->right) p=p->right;
                p->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
        }
        
        return;
    }
};