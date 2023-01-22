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
//Naive DFS
class Solution {
public:
    void inorder(TreeNode* root , vector<int>&vec){
        if(!root) return;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>vec;
        int ans=INT_MAX;
        inorder(root,vec);
        for(int i=0;i<vec.size()-1;i++)
            ans=min(ans,abs(vec[i]-vec[i+1]));
        return ans;
    }
};