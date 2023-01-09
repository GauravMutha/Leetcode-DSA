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
    vector<vector<int>>ans;
    vector<vector<int>> pathSum(TreeNode* root, int k) {
        dfs(root,k,{});
        return ans;
    }
    void dfs(TreeNode* root , int k , vector<int>vec){
        if(!root) return;
        
        vec.push_back(root->val);
        if(!root->left && !root->right && (k==root->val))
            ans.push_back(vec);
        
        dfs(root->left ,k-root->val,vec);
        dfs(root->right ,k-root->val,vec);
    }
};