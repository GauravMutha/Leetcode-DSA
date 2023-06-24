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
//Searching tree for target of every node that makes up the sum
class Solution {
public:
    bool search(TreeNode* root,int target){
        if(root==NULL) return false;
        
        bool left=false,right=false;
        if((root->val)==target) return true;
        else if(root->val>target) left=search(root->left,target);
        else if(root->val<target) right=search(root->right,target);
        
        return (left||right);
    }
    bool dfs(TreeNode* curr,TreeNode* root,int sum){
        if(curr==NULL) return false;
        
        int target=sum-curr->val;
        
        if(target!=curr->val && search(root,target)) return true;
        
        return (dfs(curr->left,root,sum) || dfs(curr->right,root,sum));
        
    }
    bool findTarget(TreeNode* root, int k) {
        TreeNode* curr=root;
        return dfs(curr,root,k);     
    }
};