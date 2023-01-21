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
//During deserialization we are inserting everytime starting from the root making it O(nlogn)
//using stringstream in deserialization

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
    //constructing bst from preorder
    TreeNode* insert(TreeNode* root , int val){
        if (root == NULL) {
			TreeNode* temp=new TreeNode(val);
			return temp;
		}
    
		if (val<=root->val)
			root->left=insert(root->left,val);
    
		else
			root->right=insert(root->right,val);
    
		return root;
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
        TreeNode* root=NULL;
        string str;
        while(getline(s,str,','))
            root=insert(root,stoi(str));
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;