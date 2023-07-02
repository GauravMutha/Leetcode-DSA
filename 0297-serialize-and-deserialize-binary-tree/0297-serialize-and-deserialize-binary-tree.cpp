/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//BFS
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr;
        string data;
        while(!q.empty()){
            curr=q.front() , q.pop();
            if(curr) data.append(to_string(curr->val)+',');
            else data.append("#,");
            
            if(curr){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        string str;
        stringstream s(data);
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str)) , *curr=NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            curr=q.front() , q.pop();
            
            //make left child
            getline(s,str,',');
            if(str=="#") curr->left=NULL;
            else{
                curr->left=new TreeNode(stoi(str));
                q.push(curr->left);
            }
            
            //make right child
            getline(s,str,',');
            if(str=="#") curr->right=NULL;
            else{
                curr->right=new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));