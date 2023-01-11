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
//DFS Top-Down
//*Disdvantage-Adding new character in the beginning of string makes it O(n) every time
class Solution {
public:
    string ans="~";
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
    void dfs(TreeNode* curr , string s){
        if(!curr) return;
        if(!curr->left && !curr->right){
            ans=min(ans,char(curr->val+'a')+s); //*here
        }
        dfs(curr->left,char(curr->val+'a')+s); //*here
        dfs(curr->right,char(curr->val+'a')+s); //* and here
    }
};