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
/*Previous submission gives TLE , because queries size is big,
its better that we first create an sorted array of nodes and
binary search there, , rather than searching tree every time*/
class Solution {
public:
    void inorder(TreeNode *curr, vector<int>& res) {
        if(curr==NULL) return;
        inorder(curr->left,res);
        res.push_back(curr->val);
        inorder(curr->right,res);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>nodesArr;
        vector<vector<int>>res;
        inorder(root,nodesArr);
        for(auto q:queries){
            
            int cInd=lower_bound(nodesArr.begin(),nodesArr.end(),q)-nodesArr.begin();
            int cVal=(cInd>=nodesArr.size())?-1 : nodesArr[cInd];
            
            int fVal=-1;
            if(cVal==q) fVal=cVal;
            else if(cVal==-1) fVal=nodesArr.back();
            else if(cInd>0) fVal=nodesArr[cInd-1]; 
            
            res.push_back({fVal,cVal});
        }
        return res;
    }
};