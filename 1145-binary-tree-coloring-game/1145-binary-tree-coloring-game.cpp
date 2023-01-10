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
//DFS
class Solution {
public:
    int leftSubNodes =0,rightSubNodes=0;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        dfs(root,x);
        int parentSubNodes=n-leftSubNodes-rightSubNodes-1;
        return ( max(max(leftSubNodes,rightSubNodes),parentSubNodes)>(n/2) );
    }
    
    int dfs(TreeNode* curr , int &x){
        if(!curr) return 0;
        int l=dfs(curr->left,x);
        int r=dfs(curr->right,x);
        
        if(curr->val==x) leftSubNodes=l ,rightSubNodes=r;
        
        return l+r+1;
        
    }
};