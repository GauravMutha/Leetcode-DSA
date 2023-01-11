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
//Purely iterative
//real O(1)
//No implicit stack space of recursion even
class Solution {
public:
    Node* connect(Node* root) {
        auto dummy=new Node(-1);
        Node *head , *p ,*curr;
        head=root , p=dummy;
        while(head){
            curr=head;
            while(curr){
                if(curr->left) p->next=curr->left , p=p->next;
                if(curr->right) p->next=curr->right , p=p->next;
                
                curr=curr->next;
            }
            head=dummy->next;
            dummy->next=NULL;
            p=dummy;
        }
        
        return root;
    }
};