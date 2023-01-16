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
//BFS
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        pair<TreeNode*,long long> curr;
        long long res=1;
        while(!q.empty()){
            int sz=q.size();
            long long start=q.front().second , end=q.back().second;
            res=max(res,end-start+1);
            for(int i=0;i<sz;i++){
                curr=q.front() , q.pop();
                long long idx=curr.second-start;
                
                if(curr.first->left) q.push({curr.first->left , (long long)2*idx+1});
                if(curr.first->right) q.push({curr.first->right,(long long)2*idx+2});
            }
        }
        return (int)res;
    }
};