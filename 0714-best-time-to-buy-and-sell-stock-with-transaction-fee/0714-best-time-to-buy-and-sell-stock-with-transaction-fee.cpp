//greedy , no DP
class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) {
        int profit=0;
        int min=prices[0];
        
        for(auto &currPrice : prices){
            if(currPrice<min) min=currPrice;
            else if((currPrice-min-fee)>0){
                profit+=currPrice-min-fee;
                min=currPrice-fee;
            }
        }
        
        return profit;
    }
};