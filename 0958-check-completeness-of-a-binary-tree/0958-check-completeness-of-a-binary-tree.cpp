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
//BFS -1 Pass
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool pre=true;
        TreeNode* curr;
        while(!q.empty()){
            curr=q.front(), q.pop();
            if(curr==NULL) pre=false;
            else{
                if(pre==false) return false;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        return true;
    }
};