/*Exactly similar , only change is that
when we sell we go to ind+2*/

//Tabulation (but with index shifting instead of any initialisation of dp)
//Bit more concise

class Solution {
public:
        int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        
        for(int ind=n-1;ind>=0;ind--){
            
            int buy=-prices[ind]+dp[ind+1][0];
            int skipBuying=dp[ind+1][1];
            dp[ind][1]=max(buy,skipBuying);
            
            int sell=+prices[ind]+dp[ind+2][1];
            int skipSelling=dp[ind+1][0];
            dp[ind][0]=max(sell,skipSelling);
            
        }
        
        return dp[0][1];
    }
};