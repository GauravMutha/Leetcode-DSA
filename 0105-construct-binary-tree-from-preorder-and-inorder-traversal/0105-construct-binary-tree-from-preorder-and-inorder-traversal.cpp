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
    int preorderInd=0;
    unordered_map<int,int>inorderMap;
public:
    TreeNode* helper(int start,int end,vector<int>& preorder){
        if(start>end) return NULL;
        auto curr=new TreeNode(preorder[preorderInd]);
        int pos=inorderMap[preorder[preorderInd++]];
        
        curr->left=helper(start,pos-1,preorder);
        curr->right=helper(pos+1,end,preorder);
        
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        
        for(int i=0;i<n;i++)
            inorderMap[inorder[i]]=i;
        
        return helper(0,n-1,preorder);
    }
};