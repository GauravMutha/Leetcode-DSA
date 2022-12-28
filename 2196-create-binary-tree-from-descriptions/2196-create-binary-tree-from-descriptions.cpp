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
//Concept same as previous one but we use only on map
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int,TreeNode*>getNode;
        int xr=0;
        TreeNode* ans=NULL;
        for(auto &v : des){
            if(getNode.count(v[0])==0){
                auto par=new TreeNode(v[0]);
                getNode[v[0]]=par;
                xr^=v[0];
            }
            if(getNode.count(v[1])==0){
                auto ch=new TreeNode(v[1]);
                getNode[v[1]]=ch;
                xr^=v[1];
            }
            if(v[2]==1) getNode[v[0]]->left=getNode[v[1]];
            else getNode[v[0]]->right=getNode[v[1]];
        }
        for(auto &v : des){
            xr^=v[1];
        }
        ans=getNode[xr];
        return ans;
    }
};