class StockSpanner {
private:
    stack<pair<int,int>>st;
    int ind; //we are making prices a zero indexed sequence
public:
    StockSpanner() {ind=-1;}
    
    int next(int price) {
        int res=0;
        ind++;
        while(st.size() && st.top().first<=price)
            st.pop();
        
        if(st.empty())
            res=ind+1;
        else
            res=ind-st.top().second;
        
        st.push({price,ind});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */