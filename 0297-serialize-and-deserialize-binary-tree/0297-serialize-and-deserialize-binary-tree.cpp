/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//DFS PREORDER
class Codec {
private: 
    void preorder(TreeNode* root , string &res){
        if(!root){
            res.append("#,");
            return;
        }
        res.append(to_string(root->val)+',');
        
        preorder(root->left,res);
        preorder(root->right,res);
    }
    TreeNode* helper(stringstream &s){
        string str;
        getline(s,str,',');
        
        if(str=="#") return NULL;
        
        auto node= new TreeNode(stoi(str));
        node->left=helper(s);
        node->right=helper(s);
        
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string data;
        preorder(root,data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        stringstream s(data);
        return helper(s);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));