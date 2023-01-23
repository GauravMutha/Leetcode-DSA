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
    TreeNode* inPre(TreeNode* root){
        while(root && root->right) root=root->right;
        return root;
    }
    TreeNode* inSucc(TreeNode* root){
        while(root && root->left) root=root->left;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key<root->val)
            root->left=deleteNode(root->left,key);
        else if(key>root->val)
            root->right=deleteNode(root->right,key);
        else{
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }
            else if(root->right==NULL){
                TreeNode* q=inPre(root->left);
                root->val=q->val;
                root->left=deleteNode(root->left,q->val);
            }
            else{
                TreeNode* q=inSucc(root->right);
                root->val=q->val;
                root->right=deleteNode(root->right,q->val);
            }
        }
        
        return root;
    }
};