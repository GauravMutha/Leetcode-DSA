class LRUCache {
private:
    int limit,sz=0;
    deque<int>q;
    unordered_map<int,int>m,trash;
public:
    LRUCache(int capacity) {
        limit=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        
        if(q.back()!=key){
            q.push_back(key);
            trash[key]++;
        }
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key)==m.end()){
            m[key]=value;
            q.push_back(key);
            sz++;
            while(sz>limit && q.size()>0){
                int poppedKey=q.front();
                q.pop_front();
                if(trash.find(poppedKey)==trash.end()) sz-- , m.erase(poppedKey);
                else{
                    trash[poppedKey]--;
                    if(trash[poppedKey]==0) trash.erase(poppedKey);
                }
            }
        }
        else{
            q.push_back(key);
            m[key]=value;
            trash[key]++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */