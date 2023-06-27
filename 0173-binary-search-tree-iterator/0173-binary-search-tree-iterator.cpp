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
class BSTIterator {
public:
    vector<int>vec;
    
    void inorder(TreeNode* curr){
        if(curr==NULL) return;
        
        inorder(curr->right);
        vec.push_back(curr->val);
        inorder(curr->left);
        
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        
        int x=vec.back();
        vec.pop_back();
        
        return x;
    }
    
    bool hasNext() {
        return vec.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */