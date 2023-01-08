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
//dfs
//reversing the answer of question 102.Binary Tree Level Order Traversal
class Solution {
public:
    vector<vector<int>>ans;
    void dfs(TreeNode* curr , int level){
        if(curr==NULL) return;
        if(level>=ans.size()) ans.push_back({curr->val});
        else ans[level].push_back(curr->val);
        
        dfs(curr->left,level+1);
        dfs(curr->right,level+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root,0);
        reverse(begin(ans),end(ans));
        return ans;
    }
};