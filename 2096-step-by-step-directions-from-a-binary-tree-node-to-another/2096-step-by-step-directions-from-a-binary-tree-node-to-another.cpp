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
//NO LCA METHOD
//ROOT TO TARGETS  THEN FILTERING THE PATH STRING
class Solution {
public:
    //PATH FOR LCA TO TAREGT NODES WITH VALUE K
    bool traverse(TreeNode* root,string &str,int &k){
        if(!root) return false;
        if(root->val==k) return true;
        
        str.push_back('L');
        if(traverse(root->left,str,k)) return true;
        str.pop_back();
        
        str.push_back('R');
        if(traverse(root->right,str,k)) return true;
        str.pop_back();
        
        return false;
    }
    string getDirections(TreeNode* root, int start, int dest) {
        
        string startString="" , destString="";
        traverse(root,startString,start);
        traverse(root,destString,dest);
        
        int i=0,j=0;
        for(;i<startString.size() && j<destString.size();i++,j++){
            if(startString[i]!=destString[j]) break;
        }
        
        return string(startString.size()-i,'U')+destString.substr(j);
        
    }
};