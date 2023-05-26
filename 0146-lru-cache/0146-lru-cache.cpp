class LRUCache {
    
private:
    class Node{
      public:
        int key,val;
        Node *next, *prev;
        
        Node(int k,int v){
            key=k;
            val=v;
        }
    };
    
    int limit;
    unordered_map<int,Node*>m;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    
public:
    LRUCache(int capacity) {
        limit=capacity;
        
        head->next=tail;
        head->prev=NULL;
        tail->prev=head;
        tail->next=NULL;
    }
    
    void addNode(Node* node){
        auto temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
    }
    
    void deleteNode(Node* delNode){
        Node* delNodePrev=delNode->prev;
        Node* delNodeNext=delNode->next;
        
        delNodePrev->next=delNodeNext;
        delNodeNext->prev=delNodePrev;
    }
    
    int get(int k) {
        if(m.find(k)==m.end()) return -1;
        
        Node* resNode=m[k];
        int retVal=resNode->val;
        
        deleteNode(resNode);
        addNode(resNode);
        /*Here we do not need to 
        change or delete in map as
        deleteNode and addNode
        are perfomed on node with
        same address*/
        return retVal;
    }
    
    void put(int k, int v) {
        if(m.find(k)!=m.end()){
            Node* existingNode=m[k];
            m.erase(k);
            deleteNode(existingNode);
        }
        if(limit==m.size()){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(k,v));
        m[k]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */