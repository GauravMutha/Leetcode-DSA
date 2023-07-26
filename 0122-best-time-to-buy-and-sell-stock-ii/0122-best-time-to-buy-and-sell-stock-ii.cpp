//DP
//Memoization
class Solution {
public:
    int helper(int ind,int canBuy,vector<int>& prices,vector<vector<int>>& dp){
        if(ind==(prices.size())) return 0;
        
        if(dp[ind][canBuy]!=-1) return dp[ind][canBuy];
        
        int profit=0;
        if(canBuy==1){
            int buy=-prices[ind]+helper(ind+1,0,prices,dp);
            int skipBuying=helper(ind+1,1,prices,dp);
            
            profit=max(buy,skipBuying);
        }
        else{
            int sell=+prices[ind]+helper(ind+1,1,prices,dp);
            int skipSelling=helper(ind+1,0,prices,dp);
            
            profit=max(sell,skipSelling);
        }
        
        return dp[ind][canBuy]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        return helper(0,1,prices,dp);
    }
};