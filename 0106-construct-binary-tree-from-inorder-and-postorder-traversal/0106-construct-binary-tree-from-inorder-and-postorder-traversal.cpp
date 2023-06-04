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
private:
    int i=0;
    unordered_map<int,int>m;
public:
    TreeNode* helper(int start,int end,vector<int>& postorder){
        if(start>end) return NULL;
        auto node=new TreeNode(postorder[i]);
        int pos=m[postorder[i--]];
        
        node->right=helper(pos+1,end,postorder);
        node->left=helper(start,pos-1,postorder);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        i=n-1;
        return helper(0,n-1,postorder);
    }
};