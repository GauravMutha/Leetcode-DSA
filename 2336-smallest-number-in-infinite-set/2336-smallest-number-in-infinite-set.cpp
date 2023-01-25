class SmallestInfiniteSet {
private : 
    int ind=1;
    vector<int>vec = std::vector<int>(1001);
public:
    SmallestInfiniteSet() {
       vec[0]=-1;
       for(int i=1;i<=1000;i++) vec[i]=i;
    }
    
    int popSmallest() {
        int ans=vec[ind];
        vec[ind]=-1;
        while(ind<vec.size() && vec[ind]==-1) ind++;
        return ans;
    }
    
    void addBack(int num) {
        if(vec[num]!=-1) return;
        vec[num]=num;
        if(vec[num]<vec[ind]) ind=num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */