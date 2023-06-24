class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),maxProfit=0 , maxToRight=-1;
        
        for(int i=n-1;i>=0;i--){
            maxToRight=max(maxToRight,prices[i]);
            maxProfit=max(maxToRight-prices[i],maxProfit);
        }
        
        return maxProfit;
    }
};