//2 heaps 2 maps
class StockPrice {
private:
    unordered_map<int,int>m;
    unordered_map<int,int>freq;
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    int latest=0 ,latestPrice=0;
public:
    StockPrice() {
        
    }
    
    void update(int ts, int price) {
        if(m.count(ts)){
            freq[m[ts]]--;
            //cleaning old incorrect prices from heaps
            while(!maxh.empty() && freq[maxh.top()]==0) 
                maxh.pop();
            while(!minh.empty() && freq[minh.top()]==0) 
                minh.pop();
        }
        m[ts]=price;
        if(freq[price]==0) maxh.push(price) , minh.push(price);
        freq[price]++; // or freq[m[ts]]++;
        if(ts>=latest){
            latest=ts;
            latestPrice=price;
        }
    }
    
    int current() {
        return latestPrice;
    }
    
    int maximum() {
        return maxh.top();
    }
    
    int minimum() {
        return minh.top();
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