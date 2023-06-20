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
//Iterative
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        auto root=new TreeNode(preorder[0]) , p=root;
        stack<TreeNode*>st;
        for(int i=1;i<preorder.size();){
            if(preorder[i]<p->val){
                auto temp=new TreeNode(preorder[i]);
                p->left=temp;
                st.push(p);
                p=temp;
                i++;
            }
            else{
                if(st.empty() || (preorder[i]<st.top()->val)){
                    auto temp=new TreeNode(preorder[i]);
                    p->right=temp;
                    p=temp;
                    i++;
                }
                else p=st.top() , st.pop();
            }
        }
        return root;
    }
};