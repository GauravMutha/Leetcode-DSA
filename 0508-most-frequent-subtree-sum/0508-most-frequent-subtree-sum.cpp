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
//DFS postorder only change is the maxCount variable that gets the maximum frequency in the recursive function itself
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        unordered_map<int,int>m;
        int maxCount=-1;
        dfs(root,m,maxCount);
        for(auto &[key,value]:m){
            if(value==maxCount) ans.push_back(key);
        }
        return ans;
    }
    
    int dfs(TreeNode* curr , unordered_map<int,int>&m,int &maxCount){
        if(curr==NULL) return 0;
        int sum=curr->val;
        sum+=dfs(curr->left,m,maxCount);
        sum+=dfs(curr->right,m,maxCount);
        m[sum]++;
        maxCount=max(maxCount,m[sum]);
        return sum;
    }
};