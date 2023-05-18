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
//recursive bfs- without using queue(only implicit recursion stack space)
class Solution {
public:
    void helper(TreeNode* curr,int level,vector<vector<int>>& res){
        if(curr==NULL) return;
        if(level<res.size()) res[level].push_back(curr->val);
        else res.push_back(vector<int>({curr->val}));
        
        helper(curr->left,level+1,res);
        helper(curr->right,level+1,res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        int level=0;
        helper(root,level,res);
        return res;
    }
};