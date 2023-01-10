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
        vector<vector<int>>ans;
        
        queue<TreeNode*>q;
        q.push(root);
        
        int level=0;
        TreeNode* curr;
        while(!q.empty()){
            int sz=q.size();
            vector<int>vec(sz);
            for(int i=0;i<sz;i++){
                curr=q.front() , q.pop();
                
                if(level%2) vec[sz-i-1]=curr->val;
                else vec[i]=curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level++;
            ans.push_back(vec);
        } 
        return ans;
    }
};