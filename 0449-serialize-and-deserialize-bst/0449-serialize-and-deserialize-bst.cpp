/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//DFS-Preorder serialization
//seperated by commas
//During deserialization we are using a seperate function instead of stringstream to get the int values for nodes from data string
//O(n)
//using substr instead of stringstream i.e. sending data string fully in deserialize function

class Codec {
private:
    void preorder(TreeNode* root , string &res){
        if(!root){
            return;
        }
        res.append(to_string(root->val)+',');
        
        preorder(root->left,res);
        preorder(root->right,res);
    }
    int getValue(string &data , int &pos){
        pos=data.find(',');
        return stoi(data.substr(0,pos));
    }
    TreeNode* helper(string &data,int maxVal){
        if(data=="") return NULL;
        
        int pos=0;
        int x=getValue(data,pos);
        if(x>maxVal) return nullptr;
        
        auto node = new TreeNode(x);
        data=data.substr(pos+1);
        node->left=helper(data,node->val);
        node->right=helper(data,maxVal);
        
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
        return helper(data,INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;