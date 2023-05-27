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
class Solution {
public:
    void preorder(int height,TreeNode* curr,int& maxHeight){
        if(curr==NULL) return;
        height+=1;
        maxHeight=max(maxHeight,height);
        
        preorder(height,curr->left,maxHeight);
        preorder(height,curr->right,maxHeight);
    }
    int maxDepth(TreeNode* root) {
        int maxHeight=0;
        preorder(0,root,maxHeight);
        
        return maxHeight;
    }
};