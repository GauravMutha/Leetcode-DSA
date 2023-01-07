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
private:
    vector<int>ans;
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<bool>visit;
        dfs(root,visit,0);
        return ans;
    }
    
    void dfs(TreeNode* curr , vector<bool>&visit , int level){
        if(curr==NULL) return;
        
        if(level>=visit.size()) visit.push_back(true) , ans.push_back(curr->val);
        
        dfs(curr->right,visit , level+1);
        dfs(curr->left,visit , level+1);
    }
};