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
//S.C. -> O(1) excluding the stack space for recursion
class Solution {
private:
    vector<int>res;
    int pre=-1,count=0,maxCount=0,modeCount=0;
public:
    void handleValue(int val){
        if(val!=pre){
            pre=val;
            count=0;
        }
        count++;
        if(count>maxCount){
            maxCount=count;
            modeCount=1;
        }
        else if(count==maxCount){
            if(!res.empty()) res[modeCount]=pre;
            modeCount++;
        }
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        handleValue(root->val);
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        res.resize(modeCount);

//Note we are not resetting maxCount as thats one of the main  information from our first pass , to poulate the res vector 
        modeCount=0 , count=0 , pre=-1;
        inorder(root);
        
        return res;
    }
};