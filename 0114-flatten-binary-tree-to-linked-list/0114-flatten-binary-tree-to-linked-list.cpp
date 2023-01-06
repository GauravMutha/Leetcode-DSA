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
    void dfs(TreeNode* curr , vector<TreeNode*>& vec){
        if(!curr) return;
        vec.push_back(curr);
        
        dfs(curr->left,vec);        
        dfs(curr->right,vec);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*>vec; 
        dfs(root,vec);
        
        for(int i=0;i<vec.size();i++){
            vec[i]->right=(i<vec.size()-1) ? vec[i+1] : NULL;
            vec[i]->left=NULL;
        }
    }
};