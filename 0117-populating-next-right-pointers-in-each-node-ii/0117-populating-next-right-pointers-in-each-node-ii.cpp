/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//DFS
//2 recursive functions
class Solution {
public:
    Node* exploreForNext(Node* curr){
        if(!curr) return NULL;
        else if(curr->left) return curr->left;
        else if(curr->right) return curr->right;
        return exploreForNext(curr->next);
    }
    void dfs(Node* root){
        if(!root) return;
        if(root->left){
            if(root->right) root->left->next=root->right;
            else root->left->next=exploreForNext(root->next);
        }
        if(root->right){
            root->right->next=exploreForNext(root->next);
        }
        
        dfs(root->right);
        dfs(root->left);
    }
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};