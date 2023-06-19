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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>ql,qr;
        ql.push(root->left);
        qr.push(root->right);
        
        while(ql.size() && qr.size()){
            auto curr1=ql.front() , curr2=qr.front();
            ql.pop() , qr.pop();
            
            if(curr1==NULL && curr2==NULL) continue;
            
            if(curr1==NULL || curr2==NULL || curr1->val!=curr2->val)
                return false;
            
            ql.push(curr1->left);
            ql.push(curr1->right);
            qr.push(curr2->right);
            qr.push(curr2->left);
        }
        
        return true;
    }
};