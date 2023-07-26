//greedy , no DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0 , n=prices.size();
        
        for(int i=1;i<n;i++){
            if(prices[i-1]>prices[i]) continue;
            profit+=(prices[i]-prices[i-1]);
        }
        
        return profit;
    }
};