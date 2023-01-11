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
//LCA METHOD
class Solution {
public:
    //FIND LCA
    TreeNode* find_lca(TreeNode* curr,int &start,int &dest){
        if(!curr) return NULL;
        if(curr->val==start || curr->val==dest) return curr;
        
        TreeNode *leftRet=find_lca(curr->left,start,dest);
        TreeNode *rightRet=find_lca(curr->right,start,dest);
        
        if(leftRet && rightRet) return curr;
        
        return leftRet?leftRet:rightRet;
    }
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
        TreeNode* lca=find_lca(root,start,dest);
        
        string startString="" , destString="";
        traverse(lca,startString,start);
        traverse(lca,destString,dest);
        
        for(auto &c : startString) c='U';
        
        return startString+destString;
        
    }
};