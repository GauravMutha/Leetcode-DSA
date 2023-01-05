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
//DFS preorder
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        dfs(root,0,ans);
        return ans;
    }
    void dfs(TreeNode* curr, int level, vector<int>& vec){
        if(curr==NULL) return;
        
        if(level>=vec.size()) vec.push_back(curr->val);
        else vec[level]=max(vec[level],curr->val);
        
        dfs(curr->left,level+1,vec);
        dfs(curr->right,level+1,vec);
    }
};