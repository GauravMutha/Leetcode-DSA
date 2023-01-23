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
//More Concise
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key<root->val)
            root->left=deleteNode(root->left,key);
        else if(key>root->val)
            root->right=deleteNode(root->right,key);
        else{
            if(root->left==NULL && root->right==NULL) return NULL;
            else if(root->left==NULL || root->right==NULL)
                return (root->left) ? root->left : root->right;
            
            TreeNode* q=root->left;
            while(q && q->right) q=q->right;
            root->val=q->val;
            root->left=deleteNode(root->left,q->val);
        }
        
        return root;
    }
};