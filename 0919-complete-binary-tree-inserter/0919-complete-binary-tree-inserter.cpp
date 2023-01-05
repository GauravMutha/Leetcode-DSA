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
class CBTInserter {
private:
    queue<TreeNode*>q;
    TreeNode* ans;
public:
    CBTInserter(TreeNode* root) {
        ans=root;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            temp=q.front();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            
            if(temp->left && temp->right) q.pop();
            else break;
        }
    }
    
    int insert(int val) {
        auto node=new TreeNode(val);
        TreeNode* temp=q.front();
        if(!temp->left){
            temp->left=node;
        }
        else {
            temp->right=node;
            q.pop();
        }
        q.push(node);
        return temp->val;
    }
    
    TreeNode* get_root() {
        return ans;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */