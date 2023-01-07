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
//DFS
class Solution {
public:
    unordered_map<int,int>findIn;
    int i=0;
    TreeNode* dfs(vector<int>&preorder,int start , int end){
        if(start>end) return NULL;
        
        auto node= new TreeNode(preorder[i]);
        int pos=findIn[preorder[i++]];
        node->left=dfs(preorder,start,pos-1);
        node->right=dfs(preorder,pos+1,end);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            findIn[inorder[i]]=i;
        }
        return dfs(preorder,0,inorder.size()-1);
    }
};