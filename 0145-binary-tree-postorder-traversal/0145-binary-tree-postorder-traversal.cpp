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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,bool>>st; //a false second mean do not print the node
        TreeNode* t=root;
        vector<int>res;
        while(t!=NULL || st.size()){
            if(t!=NULL){
                st.push({t,false});
                t=t->left;
            }
            else{
                auto temp=st.top();
                st.pop();
                if(temp.second==false){
                    st.push({temp.first,true});
                    t=temp.first->right;
                }
                else{
                    res.push_back(temp.first->val);
                    t=NULL;
                }
            }
        }
        
        return res;
    }
};