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
//Recursive
class Solution {
public:
    int i=0;
    TreeNode* bstFromPreorder(vector<int>& pre , int maxVal=INT_MAX){
        if(i==pre.size() || pre[i]>maxVal) return NULL;
        
        auto node=new TreeNode(pre[i++]);
        
        node->left=bstFromPreorder(pre,node->val);
        node->right=bstFromPreorder(pre,maxVal);
        
        return node;
    }
};