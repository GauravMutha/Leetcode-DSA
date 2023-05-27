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
//Iterative solution apart from the trivial recursive one
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>res;
        auto curr=root;
        while(curr!=NULL || st.size()>0){
            if(curr!=NULL){
                res.push_back(curr->val);
                st.push(curr);
                curr=curr->left;
            }
            else {
                auto node=st.top();
                st.pop();
                curr=node->right;
            }
        }
        
        return res;
    }
};