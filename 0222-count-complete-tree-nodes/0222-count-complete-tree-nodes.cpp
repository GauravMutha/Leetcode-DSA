//Binary search-esque
//TC-->O(log(n)^2);
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int lh=0,rh=0;
        //calculating left hright of a subtree
        auto node=root;
        while(node){
            lh++;
            node=node->left;
        }
        //calculating height of right subtree of root
        node=root;
        while(node){
            rh++;
            node=node->right;
        }
        
        if(lh==rh) return pow(2,lh)-1;
        
        return 1+ countNodes(root->left) + countNodes(root->right);
    }
};