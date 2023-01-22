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
    void inorder(TreeNode* root, int &pre , vector<int>&res,int &count,int &maxCount){
        if(!root) return;
        inorder(root->left,pre,res,count,maxCount);
        
        if(pre==root->val) count++;
        else count=1;
        
        if(count==maxCount){
            res.push_back(root->val);
        }
        else if(count>maxCount){
            res={};
            res.push_back(root->val);
            maxCount=count;
        }
        
        pre=root->val;
        
        inorder(root->right,pre,res,count,maxCount);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>res;
        int pre=-1, count=1,maxCount=INT_MIN;
        inorder(root,pre,res,count,maxCount);
        if(res.size()==0) res.push_back(root->val);
        return res;
    }
};