class LRUCache {
private:
    
    class Node{
        public:
            int key,val;
            Node* next , *prev;
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
        tail->next=NULL;
        tail->prev=head;
        head->prev=NULL;
    }
    
    void deleteNode(Node* node){
        
        auto behind=node->prev;
        auto ahead=node->next;
        
        behind->next=ahead;
        ahead->prev=behind;
    }
    
    void addNode(Node* node){
        auto temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
    }
    
    int get(int key) {
        
        if(m.find(key)==m.end()) return -1;
        
        auto node=m[key];
        int retVal=node->val;
        
        deleteNode(node);
        addNode(node);
        
        return retVal;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            
            auto node=m[key];
            m.erase(key);
            
            deleteNode(node);
        }
        if(m.size()==limit){
            
            m.erase(tail->prev->key);
            
            deleteNode(tail->prev);
        }
        
        auto freshNode=new Node(key,value);
        addNode(freshNode);
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */