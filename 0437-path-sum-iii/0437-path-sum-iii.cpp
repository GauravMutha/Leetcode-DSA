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
//DFS- preorder
//Using map
class Solution {
public:
    unordered_map<long long,int>m{{0,1}};
    int ans=0;
    void dfs(TreeNode* curr, int &k, long long sum){
        if(!curr) return;
        sum+=(long long)curr->val;
        if(m.count(sum-k)) ans+=m[sum-k];
        m[sum]++;
        dfs(curr->left,k,sum);
        dfs(curr->right,k,sum);
        m[sum]--;
        if(m[sum]==0) m.erase(sum);
    }
    int pathSum(TreeNode* root, int k) {
        dfs(root,k,0);
        return ans;
    }
};