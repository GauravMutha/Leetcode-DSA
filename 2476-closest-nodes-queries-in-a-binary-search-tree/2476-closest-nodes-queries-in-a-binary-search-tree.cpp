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
//binary search
//(mlog(n)) where m is queries size
class Solution {
private:
    void inorder(TreeNode *root,vector<int>&nodes){
        
        if(!root) return;
        
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>>res;
        
        vector<int>nodes;
        nodes.push_back(-1);
        inorder(root,nodes);
        nodes.push_back(INT_MAX);
        
        for(int i=0;i<queries.size();i++){
            int val=queries[i];
            vector<int>ans(2);
            auto indx=lower_bound(begin(nodes),end(nodes),val)-begin(nodes);
            
            if(nodes[indx]==val){
                ans[0]=nodes[indx];
                ans[1]=nodes[indx];
            }
            else {
                ans[0]=nodes[indx-1];
                ans[1]=(nodes[indx]==INT_MAX) ? -1 : nodes[indx];
            }
            
            res.push_back(ans);
        }
        
        return res;
    }
};