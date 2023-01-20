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
//INORDER DFS
class Solution {
public:
    void inorder(TreeNode* root , TreeNode* &head ,TreeNode* &pre){
        if(!root) return;
        
        inorder(root->left,head,pre);
        
        if(head==NULL){
            head=root;
            pre=head;
        }
        else{
            pre->right=root;
            pre->left=NULL;
            pre=root;
        }
        
        inorder(root->right,head,pre);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* pre=NULL;
        TreeNode* head=NULL;
        
        inorder(root,head,pre);
        
        pre->right=NULL;
        pre->left=NULL;
        
        return head;
    }
};