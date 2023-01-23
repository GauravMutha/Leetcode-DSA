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
//sc-->O(n) excluding the implicit stack space used by recursion
class Solution {
public:
    TreeNode* firstMistake,*secondMistake,*pre;
    void recoverTree(TreeNode* root) {
        if(!root) return;
        pre=new TreeNode(INT_MIN);
        inorder(root);
        swap(firstMistake->val,secondMistake->val);
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(firstMistake==NULL && pre->val>root->val){
            firstMistake=pre;
        }
        if(firstMistake!=NULL && pre->val>root->val){
            secondMistake=root;
        }
        pre=root;
        inorder(root->right);
    }
};