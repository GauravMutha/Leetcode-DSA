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
//Slughtly optmisied DFS
//We use only one vector vec and pass it by reference
//we are able to do so because we pop back the node once we are done processing it i.e. we are following the backtracking method
class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> pathSum(TreeNode* root, int k) {
        vector<int>vec;
        dfs(root,k,vec);
        return ans;
    }
    void dfs(TreeNode* root , int k , vector<int>&vec){
        if(!root) return;
        
        vec.push_back(root->val);
        if(!root->left && !root->right && (k==root->val))
            ans.push_back(vec);
        else{
            dfs(root->left ,k-root->val,vec);
            dfs(root->right ,k-root->val,vec);
        }
        vec.pop_back();
    }
};