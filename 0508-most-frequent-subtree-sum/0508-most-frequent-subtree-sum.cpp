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
//DFS postorder
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        unordered_map<int,int>m;
        dfs(root,m);
        int maxSum=INT_MIN;
        for(auto &[key,value]:m){
            if(value>maxSum) maxSum=value , ans={key};
            else if(value==maxSum) ans.push_back(key);
        }
        return ans;
    }
    
    int dfs(TreeNode* curr , unordered_map<int,int>&m){
        if(curr==NULL) return 0;
        int sum=curr->val;
        sum+=dfs(curr->left,m);
        sum+=dfs(curr->right,m);
        m[sum]++;
        return sum;
    }
};