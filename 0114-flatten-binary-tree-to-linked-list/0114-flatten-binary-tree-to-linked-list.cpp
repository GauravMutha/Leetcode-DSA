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
//Using extra space
//Naive
class Solution {
public:
    void preorder(TreeNode *curr,vector<TreeNode*>& nodesArr){
        if(curr==NULL) return;
        
        nodesArr.push_back(curr);
        preorder(curr->left,nodesArr);
        preorder(curr->right,nodesArr);
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        vector<TreeNode*>nodesArr;
        preorder(root,nodesArr);
        for(int i=0;i<nodesArr.size()-1;i++){
            nodesArr[i]->left=NULL;
            nodesArr[i]->right=nodesArr[i+1];
        }
        return;
        
    }
};