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
//String serialization - O(N^2)
class Solution {
public:
    vector<TreeNode*>ans;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>m;
        dfs(root,m);
        return ans;
    }
    string dfs(TreeNode* curr , unordered_map<string,int>&m){
        if(!curr) return "";
        string s= to_string(curr->val) + "," + dfs(curr->left,m) + "," +dfs(curr->right,m);
        if(m[s]==1) ans.push_back(curr);
        m[s]++;
        
        return s;
    }
};