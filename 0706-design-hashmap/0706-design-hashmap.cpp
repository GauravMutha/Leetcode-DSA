class MyHashMap {
private:
    vector<int>vec;
public:
    MyHashMap() {};
    
    void put(int key, int value) {
        if(key>=vec.size()){
            int prevSz=vec.size();
            vec.resize(key+1);
            fill(vec.begin() + prevSz, vec.end(), -1);
        }
        vec[key]=value;
    }
    
    int get(int key) {
        if(key>=vec.size()) return -1;
        return vec[key];
    }
    
    void remove(int key) {
        if(key>=vec.size()) return;
        vec[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */