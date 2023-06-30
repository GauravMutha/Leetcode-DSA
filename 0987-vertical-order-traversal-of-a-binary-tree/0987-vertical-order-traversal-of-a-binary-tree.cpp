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
    void helper(TreeNode* curr , int row , int col,map<int,map<int,multiset<int>>>& mo){
        if(curr==NULL) return;
        
        mo[col][row].insert(curr->val);
        
        helper(curr->left,row+1,col-1,mo);
        helper(curr->right,row+1,col+1,mo);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        map<int,map<int,multiset<int>>>mo;

        helper(root,0,0,mo);
        
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