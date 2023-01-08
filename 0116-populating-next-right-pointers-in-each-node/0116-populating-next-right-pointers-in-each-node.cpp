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
//DFS - Without using extra space - MORE OPTIMIZED  AND CONCISE
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        auto lChild=root->left , rChild=root->right , nextNode=root->next;
        
        if(lChild){
            lChild->next=rChild;
            if(nextNode) rChild->next=nextNode->left;
            
            connect(lChild);
            connect(rChild);
        }
        return root;
    }
};