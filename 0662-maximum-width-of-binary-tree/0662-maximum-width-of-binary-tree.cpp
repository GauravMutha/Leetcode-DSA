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
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long res=1;
        queue<pair<TreeNode*,long long>>q;
        
        q.push({root,(long long)0});
        
        while(!q.empty()){
            
            int sz=q.size();
            long long start=q.front().second , end= q.back().second;
            res=max(res,end-start+1);
            
            for(int i=0;i<sz;i++){
                
                auto node=q.front().first;
                long long ind=q.front().second-start;
                q.pop();
                
                if(node->left) q.push({node->left,(long long)2*ind+1});
                if(node->right) q.push({node->right,(long long)2*ind+2});
            }
        
        }
        return (int)res;
    }
};