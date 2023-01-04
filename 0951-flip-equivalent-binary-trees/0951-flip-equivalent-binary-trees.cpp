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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*> q;
        TreeNode* temp1,*temp2;
        q.push(root1);
        q.push(root2);
        while(q.size()!=0)
        {
            temp1 = q.front();
            q.pop();
            temp2=q.front();
            q.pop();
            if(temp1==NULL && temp2==NULL)
                continue;
            else if(temp1==NULL || temp2==NULL || temp1->val!=temp2->val)
                return false;
            else if(issamechildren(temp1->left,temp2->left) && issamechildren(temp1->right,temp2->right))
            {
                q.push(temp1->left);
                q.push(temp2->left);
                q.push(temp1->right);
                q.push(temp2->right);
            }
            else if(issamechildren(temp1->left,temp2->right) && issamechildren(temp1->right,temp2->left))
            {
                q.push(temp1->left);
                q.push(temp2->right);
                q.push(temp1->right);
                q.push(temp2->left);
            }
            else
            {
                return false;
            }
        }
        return true;

    }
    bool issamechildren(TreeNode* node1 ,  TreeNode* node2){
        if(node1==nullptr && node2==nullptr) return true;
        else if(node1==NULL || node2==NULL || node1->val!=node2->val) return false;
        return true;
    }
};