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
//post order DFS
class Solution {
public:
    vector<TreeNode*>ans{};
    void helper(TreeNode*& node,vector<int>&vec){
        if(node==NULL) return;
        helper(node->left,vec);
        helper(node->right,vec);
        
        if(find(vec.begin(),vec.end(),node->val)!=vec.end()){
            if(node->left) ans.push_back(node->left);
            if(node->right) ans.push_back(node->right);
            node=NULL;
            delete node;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        helper(root,to_delete);
        if(root) ans.push_back(root);
        return ans;
    }
};