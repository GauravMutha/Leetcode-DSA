//Multiset and a map
class StockPrice {
private:
    multiset<int>s;
    unordered_map<int,int>m;
    int latest=-1;
public:
    StockPrice() {
        
    }
    
    void update(int ts, int price) {
        if(m.count(ts)){
            int wrongPrice=m[ts];
            auto it=s.find(wrongPrice);
            s.erase(it);
        }
        
        latest=max(ts,latest);
        m[ts]=price;
        s.insert(price);
    }
    
    int current() {
        return m[latest];
    }
    
    int maximum() {
        auto it=s.rbegin();
        return *it;
    }
    
    int minimum() {
        auto it=s.begin();
        return *it;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */