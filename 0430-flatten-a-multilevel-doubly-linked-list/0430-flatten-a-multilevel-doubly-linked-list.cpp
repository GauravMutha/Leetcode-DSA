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
        
        Node* lastChild=NULL;
        
        if(curr->child){
            
            lastChild=helper(curr->child);
            
            if(lastChild) lastChild->next=curr->next;
            if(curr->next) curr->next->prev=lastChild;
            curr->child->prev=curr;
            curr->next=curr->child;
            curr->child=NULL;
            
            curr=lastChild;
        }
        
        return (curr->next) ? helper(curr->next) : lastChild;
    }
    Node* flatten(Node* head) {
        helper(head);
        return head;
    }
};