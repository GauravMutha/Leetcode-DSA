class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count=0;
        while(!st.empty() && st.top().first<price){
            count+=st.top().second; 
            st.pop();
        }
        if(st.empty()) st.push({price,count+1});
        else{
            if(st.top().first>price) st.push({price,count+1});
            else st.top().second+=(count+1);
        }
        return (st.top().second);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */