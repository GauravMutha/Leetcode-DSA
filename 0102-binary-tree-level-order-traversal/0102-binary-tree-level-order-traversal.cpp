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
//Iterative bfs- using queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res; 
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>bag;
            for(int i=0;i<sz;i++){
                bag.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            res.push_back(bag);
        }
        return res;
    }
};