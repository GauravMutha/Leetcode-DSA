//revision

struct Node{
    int key,val,count;
    Node *prev, *next;
    Node(int k,int v){ key=k,val=v, count=1; };
};
struct List{
    int size;
    Node* head, *tail;
    List(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        
        head->next=tail;
        head->prev=NULL;
        tail->next=NULL;
        tail->prev=head;
        
        size=0;
    }
    
    void addNode(Node* node){
        auto temp=head->next;
        
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        
        size++;
    }
    
    void deleteNode(Node *node){
        auto behind=node->prev;
        auto ahead=node->next;
        
        behind->next=ahead;
        ahead->prev=behind;
        
        size--;
    }   
};
class LFUCache {
private:
    map<int,Node*>addressMap;
    map<int,List*>listMap;
    int minFreq,cacheSize,limit;
public:
    LFUCache(int capacity) {
        limit=capacity;
        minFreq=cacheSize=0;
    }
    
    void updateListMap(Node* node){
        addressMap.erase(node->key);
        listMap[node->count]->deleteNode(node);
        
        if(minFreq==node->count && listMap[node->count]->size==0)
            minFreq++;
        
        auto newList=new List();
        if(listMap.find(node->count+1)!=listMap.end()){
            newList=listMap[node->count+1];
        }
        
        node->count++;
        newList->addNode(node);
        listMap[node->count]=newList;
        
        addressMap[node->key]=node;
    }
    
    int get(int key) {
        if(addressMap.find(key)==addressMap.end()) return -1;
        
        auto node=addressMap[key];
        int retVal=node->val;
        
        updateListMap(node);
    
        return retVal;
    }
    
    void put(int key, int value) {
        if(limit==0) return;
        
        if(addressMap.find(key)!=addressMap.end()){
            auto node=addressMap[key];
            node->val=value;
            updateListMap(node);
        }
        else{
            if(limit==cacheSize){
                auto list=listMap[minFreq];
                addressMap.erase(list->tail->prev->key);
                list->deleteNode(list->tail->prev);
                
                cacheSize--;
            }
            cacheSize++;
            minFreq=1;
            
            auto list=new List();
            if(listMap.find(minFreq)!=listMap.end()){
                list=listMap[minFreq];
            }
            auto node =new Node(key,value);
            list->addNode(node);
            addressMap[key]=node;
            listMap[minFreq]=list;
            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */