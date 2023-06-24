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
//Using map for two sum here
class Solution {
public:
    set<int>st;
    bool search(TreeNode* curr,int sum){
        if(curr==NULL) return false;
        
        if(st.find(sum-curr->val)!=st.end()) return true;
        else st.insert(curr->val);
        
        return search(curr->left, sum) || search(curr->right, sum);
    }
    bool findTarget(TreeNode* root, int k) {
        return search(root,k);
    }
};