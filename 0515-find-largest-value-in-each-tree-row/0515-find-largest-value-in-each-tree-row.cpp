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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        vector<int>ans;
        int sz=0,maxVal;
        TreeNode* temp;
        q.push(root);
        while(!q.empty()){
            sz=q.size(),maxVal=INT_MIN;
            for(int i=0;i<sz;i++){
                temp=q.front() , q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                maxVal=max(maxVal,temp->val);
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};