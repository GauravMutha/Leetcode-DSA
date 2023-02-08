/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return search(original,cloned,target);
    }
    
    TreeNode* search(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(cloned==NULL) return NULL;
        
        if(original==target) return cloned;
        
        TreeNode* leftReturn= search(original->left,cloned->left,target);
        TreeNode* rightReturn = search(original->right,cloned->right,target);
        
        if(leftReturn==NULL && rightReturn==NULL) return NULL;
        
        return (leftReturn) ? leftReturn : rightReturn;
    }
};