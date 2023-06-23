/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Naive
class Solution {
private:
    unordered_map<int,TreeNode*>parent;
    vector<TreeNode*>vecP , vecQ;
public:
    void parentTracker(TreeNode* curr){
        if(curr==NULL) return;
        
        if(curr->left) parent[curr->left->val] =curr;
        if(curr->right) parent[curr->right->val]=curr;
        
        parentTracker(curr->left);
        parentTracker(curr->right);
    }
    void dfs(TreeNode* curr,vector<TreeNode*>& vec){
        if(curr==NULL) return;
        
        dfs(parent[curr->val],vec);
        vec.push_back(curr);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        parent[root->val]=NULL;
        
        parentTracker(root);
        
        dfs(p,vecP);
        dfs(q,vecQ);
        
        for(int i=0;i<min(vecP.size(),vecQ.size());i++){
            if(vecP[i]!=vecQ[i]) break;
            ans=vecP[i];
        }
        return ans;
    }
};