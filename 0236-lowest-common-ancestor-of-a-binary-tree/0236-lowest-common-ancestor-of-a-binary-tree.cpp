/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Naive DFS - 3 pass
class Solution {
public:
    unordered_map<int,TreeNode*>parent;
    void parentTracker(TreeNode* curr){
        if(!curr) return;
        if(curr->left) parent[curr->left->val]=curr;
        if(curr->right) parent[curr->right->val]=curr;
        
        parentTracker(curr->left);
        parentTracker(curr->right);
    }
    void dfs(TreeNode* curr , vector<TreeNode*>&vec){
        if(!curr) return;
        vec.push_back(curr);
        dfs(parent[curr->val],vec);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        vector<TreeNode*>vecP , vecQ;
        parent[root->val]=NULL;
        parentTracker(root);
        dfs(p,vecP);
        dfs(q,vecQ);
        int i=vecP.size()-1 , j=vecQ.size()-1;
        while(i>=0 && j>=0){
            if(vecP[i]!=vecQ[j]) break;
            ans=vecP[i];
            i-- ,j--;
        }
        return ans;
    }
};