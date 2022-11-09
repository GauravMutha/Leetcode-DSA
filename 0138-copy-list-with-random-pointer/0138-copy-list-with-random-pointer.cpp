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
        Node *curr=NULL , *p=head,*new_head,*q;
        unordered_map<Node* , Node*>m;
        while(p){
            if(curr==NULL){
                auto temp=new Node(p->val);
                curr=temp;
                m[p]=curr;
                new_head=curr;
            }
            else{
                auto temp=new Node(p->val);
                curr->next=temp;
                curr=temp;
                m[p]=curr;
            }
            p=p->next;
        }
        p=head , q=new_head;
        while(p && q){
            q->random=m[p->random];
            p=p->next , q=q->next;
        }
        return new_head;
    }
};

//2 pass