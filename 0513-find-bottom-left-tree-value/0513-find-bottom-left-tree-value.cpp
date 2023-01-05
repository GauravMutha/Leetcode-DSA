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
// BFS
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans=0;
        TreeNode* temp;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            ans=q.front()->val;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};