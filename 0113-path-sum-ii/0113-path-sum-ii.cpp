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
//Re//
//Backtracking
class Solution {
private:
    vector<vector<int>>ans;
public:
    void helper(TreeNode* currNode,vector<int>& ds,int sum,int target){
        if(currNode==NULL) return;
        
        sum+=currNode->val;
        ds.push_back(currNode->val);
        
        if(!currNode->left && !currNode->right && sum==target){
            ans.push_back(ds);
        }
        
        helper(currNode->left,ds,sum,target);
        helper(currNode->right,ds,sum,target);
        
        sum-=currNode->val;
        ds.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ds;
        helper(root,ds,0,targetSum);
        
        return ans;
    }
};