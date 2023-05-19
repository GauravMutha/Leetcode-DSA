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
// #2 DFS without extra space (and only recursion stack space)

/*Since it is a perfect binay tree.We do not need to think too 
much, left child'next connects to right child and right child's 
next connects to parent->next>left,if parent's next exists,thats it*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        auto lChild=root->left,rChild=root->right;
        if(lChild){
            lChild->next=rChild;
            if(root->next!=NULL) rChild->next=root->next->left;
            
            connect(lChild);
            connect(rChild);
        }
        /*since it is pbt,if left child does not exist, we are at
        (i.e. curr is)first leaf node, at the last level so we return*/
        return root;
    }
};