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
//previous solution was BFS
//This is DFS
class Solution {
public:
    vector<int>vec;
    bool isEvenOddTree(TreeNode* root,size_t d=0) {
        if(!root) return true;
        if(d%2 == root->val%2) return false;
        
        if(d<vec.size()){
            if((d%2==0 && vec[d]>=root->val) || (d%2 && vec[d]<=root->val))
                return false;
            vec[d]=root->val;
        }
        else {
            vec.push_back(root->val);
        }
        
        return isEvenOddTree(root->left,d+1) && isEvenOddTree(root->right,d+1);
    }
};