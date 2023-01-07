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
//BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* temp;
        
        while(!q.empty()){
            int sz=q.size();
            for(int i=1;i<=sz;i++){
                temp=q.front() , q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
                if(i==sz) ans.push_back(temp->val);
            }
        }
        
        return ans;
    }
};