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
//DFS
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL) return false;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* curr;
        int level=0;
        while(!q.empty()){
            int pre=(level%2)?INT_MAX:INT_MIN , sz=q.size();
            for(int i=0;i<sz;i++){
                curr=q.front() , q.pop();
                    
                if(level%2==0 && ((curr->val%2==0) || (pre>=curr->val))
                || level%2 && ((curr->val%2) || (pre<=curr->val)) )
                    return false;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                pre=curr->val;
            }
            level++;
        }
        return true;
    }
};