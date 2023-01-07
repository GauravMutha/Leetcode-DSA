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
private:
    unordered_map<int,int>findIn;
public:
    TreeNode* dfs(vector<int>&postorder,int start,int end,int &postIndex){
        if(start>end || postIndex<0) return NULL;
        auto node=new TreeNode(postorder[postIndex]);
        int pos=findIn[postorder[postIndex--]];
        
        node->right=dfs(postorder,pos+1,end,postIndex);
        node->left=dfs(postorder,start,pos-1,postIndex);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        vector<int>ans;
        for(int i=0;i<inorder.size();i++){
            findIn[inorder[i]]=i;
        }
        int postEnd=postorder.size()-1;
        return dfs(postorder,0,inorder.size()-1,postEnd);
    }
};