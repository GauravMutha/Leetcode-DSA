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
//DFS
//No extra Space
class Solution {
public:
    int targetHeight=0;
    bool secondLast=false;
    bool isCompleteTree(TreeNode* root , int h=0) {
        if(root==NULL){
            if(targetHeight==0) targetHeight=h;
            else if(h==targetHeight-1) secondLast=true;
            
            return h==(targetHeight-secondLast);
        }
        return isCompleteTree(root->left,h+1) && isCompleteTree(root->right,h+1);
    }
};