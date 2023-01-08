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
//DFS - Without using extra space
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        dfs(root,NULL,false);
        return root;
    }
    void dfs(Node* curr, Node* parent, bool lchild){
        if(!curr) return;
        if(parent){
            if(!lchild)curr->next=(parent->next) ? parent->next->left : NULL;
            else curr->next=parent->right;
        }
        else curr->next=NULL;
        
        dfs(curr->left,curr,true);
        dfs(curr->right,curr,false);
    }
};