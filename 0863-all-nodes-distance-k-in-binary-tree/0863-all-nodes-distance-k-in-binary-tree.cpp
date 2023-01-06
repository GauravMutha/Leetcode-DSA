/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int>ans;
    unordered_map<int,TreeNode*>parent;
    unordered_set<int>visited;
    void parentTracker(TreeNode* curr){
        if(!curr) return;
        if(curr->left){
            parent[curr->left->val]=curr;
            parentTracker(curr->left);
        }
        if(curr->right){
            parent[curr->right->val]=curr;
            parentTracker(curr->right);
        }
    }
    void dfs(TreeNode* curr,int k){
        if(!curr || visited.find(curr->val)!=visited.end()) return;
        
        visited.insert(curr->val);
        if(k==0) {
            ans.push_back(curr->val);
            return;
        }
        
        dfs(curr->left,k-1);        
        dfs(curr->right,k-1);
        dfs(parent[curr->val],k-1);

    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parentTracker(root);
        dfs(target,k);
        return ans;
    }
};