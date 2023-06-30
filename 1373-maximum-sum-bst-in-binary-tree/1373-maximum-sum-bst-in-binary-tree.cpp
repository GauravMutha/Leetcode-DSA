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
private:
    int res=0;
public:
    vector<int> helper(TreeNode* curr){
        if(curr==NULL) return {INT_MAX,INT_MIN,0};  //{min,max,sum};
        
        vector<int>leftRet=helper(curr->left);
        vector<int>rightRet=helper(curr->right);
        
        int lmin=leftRet[0],lmax=leftRet[1],lsum=leftRet[2];
        int rmin=rightRet[0],rmax=rightRet[1],rsum=rightRet[2];
        int sum=curr->val+lsum+rsum;
        
        if(curr->val<=lmax || curr->val>=rmin) return {INT_MIN,INT_MAX,0};
        
        res=max(sum,res);
        return {min(curr->val,lmin),max(curr->val,rmax),sum};
        
        
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return max(0,res);
    }
};