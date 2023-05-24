/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        
        unordered_map<Node*,Node*>m;
        Node *curr=head;
        Node* prev=NULL; 

        while(curr){
            auto newNode=new Node(curr->val);
            m[curr]=newNode;
            if(prev!=NULL) prev->next=m[curr];
            prev=m[curr];
            curr=curr->next;
        }
        curr=head;
        while(curr){
            m[curr]->random=m[curr->random];
            curr=curr->next;
        }
        curr=head;
        return m[curr];
    }
};