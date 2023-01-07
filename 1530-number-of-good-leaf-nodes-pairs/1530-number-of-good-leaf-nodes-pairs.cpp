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
class Solution {
private:
    unordered_map<TreeNode*,TreeNode*>parent;
    int ans=0;
public:
    void dfs(TreeNode* node , int steps , int& k ,unordered_map<TreeNode*,bool>&visited){
        if(!node || steps>k || visited[node]) return;
        if(!node->left && !node->right) ans++;
        visited[node]=true;
        dfs(node->left,steps+1,k,visited);
        dfs(node->right,steps+1,k,visited);
        dfs(parent[node],steps+1,k,visited);
        visited[node]=false;
    }
    int countPairs(TreeNode* root, int k) {
        queue<TreeNode*>q;
        vector<TreeNode*>leaf;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            temp=q.front() , q.pop();
            if(!temp->left && !temp->right) leaf.push_back(temp);
            if(temp->left) q.push(temp->left) , parent[temp->left]=temp;
            if(temp->right) q.push(temp->right) , parent[temp->right]=temp;
        }
        
        for(auto node : leaf){
            unordered_map<TreeNode*,bool>visited;
            visited[node]=true;
            dfs(parent[node],1,k,visited);
        }
        
        return (ans)/2;
    }
};