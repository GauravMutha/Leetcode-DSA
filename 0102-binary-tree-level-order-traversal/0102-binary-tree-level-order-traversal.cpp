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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* curr;
        while(!q.empty()){
            int sz=q.size();
            vector<int>vec;
            for(int i=0;i<sz;i++){
                curr=q.front() , q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                vec.push_back(curr->val);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};