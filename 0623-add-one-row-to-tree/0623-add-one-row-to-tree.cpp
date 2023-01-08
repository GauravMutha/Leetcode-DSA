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
//DFS - Postorder
class Solution {
public:
    TreeNode* dfs(TreeNode *&curr,int level,int k,int val){
        if(!curr) return NULL;
        auto lChild=dfs(curr->left,level+1,k,val);
        auto rChild=dfs(curr->right,level+1,k,val);
        
        if(level==(k-1)){
            auto L=new TreeNode(val,lChild,NULL);
            auto R=new TreeNode(val,NULL,rChild);
            curr->left=L;
            curr->right=R;
        }
        
        return curr;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            auto new_root = new TreeNode(val,root,NULL);
            return new_root;
        }
        return dfs(root,1,depth,val);
    }
};