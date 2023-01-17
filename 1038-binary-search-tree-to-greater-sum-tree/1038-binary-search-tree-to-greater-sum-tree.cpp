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
//BST BASED INORDER -ITERATIVE
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* curr=root, *temp=NULL;
        int accum=0;
        while(curr!=NULL){
            if(curr->right==NULL){
                accum+=curr->val;
                curr->val=accum;
                curr=curr->left;
            }
            else{
                temp=curr->right;
                while(temp->left!=NULL && temp->left!=curr)
                    temp=temp->left;
                if(temp->left==NULL){
                    temp->left=curr;
                    curr=curr->right;
                }
                else {
                    accum+=curr->val;
                    curr->val=accum;
                    temp->left=NULL;
                    curr=curr->left;
                }
            }
        }
        
        return root;
    }
};