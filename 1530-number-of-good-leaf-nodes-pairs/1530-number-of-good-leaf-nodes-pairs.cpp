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
//DFS postorder - Optimised than previous ones
class Solution {
public:
    int ans=0;
    vector<int> dfs(TreeNode* curr , int distance){
        if(!curr) return {};
        vector<int>ret;
        vector<int>left=dfs(curr->left,distance);
        vector<int>right = dfs(curr->right,distance);
        
        if(left.size()==0 && right.size()==0){
            ret.push_back(1);
            return ret;
        }
        
        for(int i=0;i<left.size();i++){
            for(int j=0;j<right.size();j++){
                if(left[i]+right[j]<=distance) ans++;
            }
        }
        
        for(auto e : left)
            ret.push_back(e+1);
        for(auto e : right)
            ret.push_back(e+1);
        
        return ret;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return ans;
    }
};