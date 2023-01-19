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
//Stack+Itertive
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre){
        int i=0;
        stack<TreeNode*>st;
        auto root=new TreeNode(pre[i++]);
        TreeNode* curr=root;
        while(i<pre.size()){
            if(pre[i]<curr->val){
                st.push(curr);
                auto node=new TreeNode(pre[i]);
                curr->left=node;
                curr=curr->left;
            }
            else{
                while(!st.empty() && pre[i]>st.top()->val){
                    curr=st.top();
                    st.pop();
                }
                auto node=new TreeNode(pre[i]);
                curr->right=node;
                curr=curr->right;
            }
            i++;
        }
        return root;
    }
};