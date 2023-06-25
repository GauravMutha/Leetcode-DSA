/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* helper(Node* curr) {
        if(curr==NULL || (curr->next==NULL && curr->child==NULL)) return curr;
        
        Node* cn=curr->next;
        Node* lastChild=NULL;
        
        if(curr->child){
            Node* cc=curr->child; //c ,means current's child
            curr->next=curr->child;
            curr->child->prev=curr;
            curr->child=NULL;
            
            lastChild=helper(cc);
            
            if(cn && lastChild) cn->prev=lastChild , lastChild->next=cn;
        }
        
        if(cn) return helper(cn);
        
        return lastChild;
    }
    Node* flatten(Node* head) {
        helper(head);
        return head;
    }
};