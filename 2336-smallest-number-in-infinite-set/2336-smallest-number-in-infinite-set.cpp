class SmallestInfiniteSet {
private:
    set<int>s;
    int curr;
public:
    SmallestInfiniteSet() {
        curr=1;
    }
    
    int popSmallest() {
        if(s.size()){
            int res=*s.begin();
            s.erase(res);
            return res;
        }
        curr++;
        return curr-1;
    }
    
    void addBack(int num) {
        if(num<curr) s.insert(num);
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */