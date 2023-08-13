class RandomizedSet {
public:
    unordered_map<int,int>m;
    vector<int>nums;
    
    RandomizedSet() {}
    
    bool insert(int val) {
        if(m.find(val)!=m.end()) return false;
        nums.push_back(val);
        m[val]=nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end()) return false;
        
        int last=nums.back();
        int valInd=m[val];
        m[last]=valInd;
        
        nums[m[val]]=last;
        nums.pop_back();
        m.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */