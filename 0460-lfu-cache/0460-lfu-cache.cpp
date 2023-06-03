struct Node{
    //The count of a node denotes its frequency
    int cnt,key,value;
    Node* next , *prev;
    Node(int k , int v){
        key=k , value=v , cnt=1;
    }
};
struct List{
    Node* head , *tail;
    int size; //The size of list (excluding the head and tail ofcourse)
    List(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        
        head->prev=NULL;
        head->next=tail;
        tail->prev=head;
        tail->next=head;
        
        size=0;
    }
    void addNodeAtListFront(Node* node){
        auto temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        
        size++;
    }
    
    void deleteNode(Node* delNode){
        Node* delNodePrev=delNode->prev;
        Node* delNodeNext=delNode->next;
        
        delNodePrev->next=delNodeNext;
        delNodeNext->prev=delNodePrev;
        
        size--;
    }
};
class LFUCache {
private:
    int limit,minFreq,cacheSize;;
    map<int,List*>listMap; // it maps frequency to its list
    map<int,Node*>addressMap; // it maps key to its node-address, that is which node represent the key
public:
    LFUCache(int capacity) {
        limit=capacity;
        minFreq=cacheSize=0;
    }
    
    void updateListMap(Node *node){
        /*remove node's key from address map and 
        remove node from listMap based on node cnt
        which is its frequency.If size of list might
        become zero here after deletion of node
        (head and tail does not count)*/
        addressMap.erase(node->key);
        listMap[node->cnt]->deleteNode(node);
        
        /*node's frequency will increase as it has been visited
        therefore if it was in list of minFreq and that frquency's
        list had become zero above after deletion of node than 
        minFreq has to be increase by one which will be same as
        node->cnt +1 soon*/
        if(minFreq==node->cnt && listMap[node->cnt]->size==0) minFreq++;
        
        
        /*In below steps we take the list which will receive the 
        node now if the icreased frequency was there in map as key
        then the new list is assigned that as this new list will add
        the node and kind of update the already existing list for the 
        frequecny Otherwise this list will be mapped as fresh new list 
        to the newly added freqeuncy in map with a node 'node' in it*/
        auto nextHigherFreqList=new List();
        if(listMap.find(node->cnt+1)!=listMap.end()){
            nextHigherFreqList=listMap[node->cnt+1];
        }
        
        node->cnt+=1;
        nextHigherFreqList->addNodeAtListFront(node);
        listMap[node->cnt]=nextHigherFreqList;
        
        addressMap[node->key]=node;
    }
    
    int get(int key) {
        if(addressMap.find(key)==addressMap.end()) return -1;
        Node* node = addressMap[key];
        int val=node->value;
        
        /*'get' changes the frequency of node
        with the given key, hence the listMap 
        and other things needs to be updated*/
        updateListMap(node);
        
        return val;
    }
    
    void put(int key, int value) {
        if(limit==0) return;
        /*If the given key node is already there
        then its frequency changes and listMap
        and other things needs to be updated just
        like how it happened in 'get' operation*/
        if(addressMap.find(key)!=addressMap.end()){
            Node* node=addressMap[key];
            node->value=value;
            updateListMap(node);
        }
        /*if it was not present then we need to add it
        into listMap by making a new list.Also since its
        the first time entering the map , its frequency
        will be one and minfrequnecy to will become 1*/
        else{
            /*But before anything we need to check if the
            new node adding will exceed the achelimit, if yes
            then we need to remove the LR and LF used node
            from iistMap*/
            if(limit==cacheSize){
                auto list=listMap[minFreq];
                addressMap.erase(list->tail->prev->key);
                listMap[minFreq]->deleteNode(list->tail->prev);
                cacheSize--;
            }
            cacheSize++;
            minFreq=1;
            /*Below procedure is same as the one in put 
            operation*/
            auto list=new List();
            if(listMap.find(minFreq)!=listMap.end()){
                list=listMap[minFreq];
            }
            auto node =new Node(key,value);
            list->addNodeAtListFront(node);
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