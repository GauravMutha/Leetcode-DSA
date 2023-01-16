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
//BST BASED BFS
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* curr;
        int ans=0;
        while(!q.empty()){
            curr=q.front() ,q.pop();
            int v=curr->val;
            ans+=(v>=low && v<=high) ? curr->val : 0;
            
            if(v>low && curr->left) q.push(curr->left); 
            if(v<high && curr->right) q.push(curr->right); 
        }
        
        return ans;
    }
};