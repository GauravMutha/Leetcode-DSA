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
//DFS preorder using vector
class Solution {
public:
    int ans=0;
    void helper(TreeNode* curr , vector<int>freq){
        if(curr==NULL){
            return;
        }
        freq[curr->val]++;
        if(curr->left==NULL && curr->right==NULL){
            if(freq.size()==0) ans=0;
            else {
                int oddCount=0;
                for(auto &e:freq) oddCount+=(e%2!=0);
                ans+=(oddCount<2);
            }
            return;
        }
        helper(curr->left,freq);       
        helper(curr->right,freq);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>freq(10,0);
        helper(root,freq);
        return ans;
    }
};