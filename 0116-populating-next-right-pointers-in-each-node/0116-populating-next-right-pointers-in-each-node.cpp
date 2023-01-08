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
//ACTUAL O(1) space i.e. not even uses sytem stack as it is an iterative solution
//Somewhat similar to BFS
class Solution {
public:
    Node* connect(Node* root) {
        auto head=root;
        for(;root;root=root->left){
            for(auto curr=root;curr;curr=curr->next){
                if(curr->left){
                    curr->left->next=curr->right;
                    if(curr->next) curr->right->next=curr->next->left;
                }
                else break;
            }
        }
        return head;
    }
};