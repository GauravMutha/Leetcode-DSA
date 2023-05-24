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
//Without using map

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *p=head,*q;
        auto dummy= new Node(-1);
        q=dummy;
        //inserting new nodes in the same list alternatively
        while(p){
            auto temp=p->next;
            p->next=new Node(p->val);
            p->next->next=temp;
            p=temp;
        }
        //setting the random pointers
        p=head;
        while(p){
            if(p->random){
                p->next->random=p->random->next;
            }
            p=p->next->next;
        }
        
        //extracting the newly made list
        p=head;
        while(p && q){
            q->next=p->next;
            q=q->next;
            
            p->next=p->next->next;
            p=p->next;
        }
        
        return dummy->next;
    }
};