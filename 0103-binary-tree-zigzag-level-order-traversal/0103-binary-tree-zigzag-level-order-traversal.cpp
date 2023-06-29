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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        int level=0;
        vector<vector<int>>res;
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(q.size()){
            int sz=q.size();
            vector<int>vec(sz);
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                
                if(level%2) vec[sz-i-1]=node->val;
                else vec[i]=node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(vec);
            level++;
        }
        
        return res;
    }
};