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
//BFS
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int k) {
        if(k==1){
            auto new_root=new TreeNode(val,root,NULL);
            return new_root;
        }
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* curr=NULL;
        int level=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                curr=q.front() , q.pop();
                if(level == (k-1)){
                    auto L=new TreeNode(val,curr->left,NULL);
                    auto R=new TreeNode(val,NULL,curr->right);
                    curr->left=L;
                    curr->right=R;
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level++;
            if(level==k) break;
        }
        return root;
    }
};