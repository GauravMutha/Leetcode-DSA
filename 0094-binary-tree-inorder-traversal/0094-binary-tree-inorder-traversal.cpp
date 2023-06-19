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
//Morris inorder traversal
//Threaded binary tree
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        auto curr=root;
        vector<int>res;
        
        while(curr){
            if(curr->left==NULL){
                res.push_back(curr->val);
                curr=curr->right;
            }
            else{
                auto p=curr->left;
                while(p->right && p->right!=curr) p=p->right;
                if(p->right==NULL){
                    p->right=curr;
                    curr=curr->left;
                }
                else{
                    p->right=NULL;
                    res.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return res;
    }
};