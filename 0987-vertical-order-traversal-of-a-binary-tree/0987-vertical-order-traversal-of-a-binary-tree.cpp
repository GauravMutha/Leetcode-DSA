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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        map<int,map<int,multiset<int>>>mo;
        queue<pair<TreeNode*,pair<int,int>>>q;
        
        q.push({root,{0,0}});
        
        while(q.size()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto node=q.front().first;
                int row=q.front().second.first , col=q.front().second.second;
                
                q.pop();
                
                mo[col][row].insert(node->val);
                
                if(node->left) q.push({node->left,{row+1,col-1}});
                if(node->right) q.push({node->right,{row+1,col+1}});
            }
        }
        
        for(auto &[col,mi]:mo){
            vector<int>vec;
            for(auto &[row,st]:mi){
                for(auto s:st) vec.push_back(s);
            }
            res.push_back(vec);
        }
        
        return res;
    }
};