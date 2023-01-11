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
//characters are added at the back of string top to down
//reversing at the end in base cases as we compare leaf to root
//passing string by reference therefore we pop_back to make same string resuable
class Solution {
public:
    string ans="~";
    string smallestFromLeaf(TreeNode* root) {
        string s="";
        dfs(root,s);
        return ans;
    }
    void dfs(TreeNode* curr , string& s){
        if(!curr) return;
        s.push_back(curr->val+'a');
        if(!curr->left && !curr->right){
            string temp=s;
            reverse(begin(temp),end(temp));
            ans=min(ans,temp);
        }
        dfs(curr->left,s);
        dfs(curr->right,s);
        s.pop_back();
    }
};